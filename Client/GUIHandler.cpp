#include "GUIHandler.h"

using namespace std;

GUIHandler::GUIHandler()
{
	loginWidget = new LoginWidget;
	createAccountWidget = new CreateAccountWidget;
	gameWidget = new GameWidget;
	accountWidget = new AccountWidget;
	stackedWidget = new StackedWidget(this->loginWidget, this->createAccountWidget, this->gameWidget, this->accountWidget);

	account = new Account();

	SetupConnections();

	SwitchView(LoginWidgetView);
}


// Links Signals from all other widgets to Handler slots
void GUIHandler::SetupConnections()
{
	// LOGIN WIDGET
	QObject::connect(loginWidget, &LoginWidget::Login, this, &GUIHandler::Login);
	QObject::connect(loginWidget, &LoginWidget::SwitchView, this, &GUIHandler::SwitchView);

	// CREATE ACCOUNT WIDGET
	QObject::connect(createAccountWidget, &CreateAccountWidget::CreateAccount, this, &GUIHandler::CreateAccount);
	QObject::connect(createAccountWidget, &CreateAccountWidget::SwitchView, this, &GUIHandler::SwitchView);

	// GAME WIDGET
	QObject::connect(gameWidget, &GameWidget::Logout, this, &GUIHandler::Logout);
	QObject::connect(gameWidget, &GameWidget::SwitchView, this, &GUIHandler::SwitchView);
	QObject::connect(gameWidget, &GameWidget::NewGame, this, &GUIHandler::NewGame);

	Ui::GameWidget* gameWidgetUI = gameWidget->GetGameWidgetUI();
	QObject::connect(gameWidgetUI->topLeft, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->topMiddle, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->topRight, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->middleLeft, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->middle, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->middleRight, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->bottomLeft, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->bottomMiddle, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);
	QObject::connect(gameWidgetUI->bottomRight, &ClickableLabel::clicked, this, &GUIHandler::MakeGameMove);


	// ACCOUNT WIDGET
	QObject::connect(accountWidget, &AccountWidget::SwitchView, this, &GUIHandler::SwitchView);
	QObject::connect(accountWidget, &AccountWidget::ChangeImage, this, &GUIHandler::ChangeImage);


}

void GUIHandler::Login(string username, string password)
{
	//emit START_CONNECTION();

	// SEND LOGIN PACKET
	char* usr = new char[username.length()+1];
	strcpy(usr, username.c_str());
	char* pwd = new char[password.length()+1];
	strcpy(pwd, password.c_str());
	/*char usr[] = "xxKarlxx";
	char pwd[] = "Conestoga";*/
	emit LOGIN(usr, pwd);

	// ON SUCCESS
	//stackedWidget->SwitchView(GameWidgetView);

	// ON FAILURE
	// do something
}

void GUIHandler::LOGIN_SUCCESS(Account* acc)
{
	account = acc;
	stackedWidget->SwitchView(GameWidgetView);
	accountWidget->UpdateUI(account);
	gameWidget->UpdateStats(account);
}

void GUIHandler::LOGIN_FAILURE()
{
	// implement error message
}

void GUIHandler::CreateAccount(string username, string password, string firstname, string lastname)
{
	char* usr = new char[username.length() + 1];
	strcpy(usr, username.c_str());
	char* pwd = new char[password.length() + 1];
	strcpy(pwd, password.c_str());
	char* fname = new char[username.length() + 1];
	strcpy(fname, username.c_str());
	char* lname = new char[password.length() + 1];
	strcpy(lname, password.c_str());

	emit CREATE_ACCOUNT(usr, pwd, fname, lname);

}

void GUIHandler::Logout()
{
	stackedWidget->SwitchView(LoginWidgetView);
	emit LOGOUT();
	//emit STOP_CONNECTION();
}

void GUIHandler::MakeGameMove(ClickableLabel* label)
{
	if (label->pixmap().isNull())
	{
		currentMove = label;
		emit GAME_MOVE(label->GetGridNum());
	}
}

void GUIHandler::UPDATE_GAME_BOARD(int computerMove)
{
	for (int i = 1; i < 10; i++)
	{
		if (gameWidget->gameLabels[i]->GetGridNum() == computerMove)
		{
			QPixmap x("assets/cross_sprite.png");
			gameWidget->gameLabels[i]->setPixmap(x);
		}
		else if (gameWidget->gameLabels[i]->GetGridNum() == currentMove->GetGridNum())
		{
			QPixmap circle("assets/circle_sprite.png");
			gameWidget->gameLabels[i]->setPixmap(circle);
		}
	}
}

void GUIHandler::GAME_STATUS(int gameCode)
{
	Ui::GameWidget* gameWidgetUI = gameWidget->GetGameWidgetUI();
	QPixmap circle("assets/circle_sprite.png");

	if (gameCode == 0)
	{
		gameWidgetUI->turnLabel->setText(QString::fromStdString("Draw Game"));
		currentMove->setPixmap(circle);
		account->incrementDraws();
	}
	else if (gameCode == 1)
	{
		gameWidgetUI->turnLabel->setText(QString::fromStdString("Player Won"));
		
		currentMove->setPixmap(circle);
		account->incrementWins();
	}
	else if (gameCode == 2)
	{
		gameWidgetUI->turnLabel->setText(QString::fromStdString("You Lost"));
		account->incrementLosses();
	}
	gameWidget->UpdateStats(account);
	gameWidget->disableGameBoard();
}

// For profile pictures
void GUIHandler::ChangeImage(QPixmap image)
{
	// SEND IMAGE PACKET
}

// Switch between windows (i.e 'widgets')
void GUIHandler::SwitchView(WIDGET_VIEW_NAME name)
{
	stackedWidget->SwitchView(name);
}

StackedWidget* GUIHandler::GetStackedWidget()
{
	return this->stackedWidget;
}


// Clear the game board
void GUIHandler::NewGame()
{
	Ui::GameWidget* gameWidgetUI = gameWidget->GetGameWidgetUI();
	gameWidgetUI->turnLabel->setText(QString::fromStdString("Your turn"));

	QPixmap blank;
	for (int i = 1; i < 10; i++)
	{
		gameWidget->gameLabels[i]->setPixmap(blank);
	}
}

