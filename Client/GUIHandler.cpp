#include "GUIHandler.h"
//#include <qwidget.h>
//#include <qscreen.h>
//#include <QApplication>

using namespace std;

GUIHandler::GUIHandler()
{
	loginWidget = new LoginWidget;
	createAccountWidget = new CreateAccountWidget;
	gameWidget = new GameWidget;
	accountWidget = new AccountWidget;
	stackedWidget = new StackedWidget(this->loginWidget, this->createAccountWidget, this->gameWidget, this->accountWidget);

	SetupConnections();

	SwitchView(LoginWidgetView);

	/*this->loginWidget = loginWidget;
	this->createAccountWidget = createAccountWidget;
	this->gameWidget = gameWidget;
	this->accountWidget = accountWidget;
	this->stackedWidget = stackedWidget;*/
}


// Links Signals from all other widgets to Handler slots
void GUIHandler::SetupConnections()
{
	QObject::connect(loginWidget, &LoginWidget::Login, this, &GUIHandler::Login);
	QObject::connect(loginWidget, &LoginWidget::SwitchView, this, &GUIHandler::SwitchView);

	QObject::connect(createAccountWidget, &CreateAccountWidget::CreateAccount, this, &GUIHandler::CreateAccount);
	QObject::connect(createAccountWidget, &CreateAccountWidget::SwitchView, this, &GUIHandler::SwitchView);

	QObject::connect(gameWidget, &GameWidget::Logout, this, &GUIHandler::Logout);
	QObject::connect(gameWidget, &GameWidget::SwitchView, this, &GUIHandler::SwitchView);

	QObject::connect(accountWidget, &AccountWidget::SwitchView, this, &GUIHandler::SwitchView);

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

	QObject::connect(accountWidget, &AccountWidget::ChangeImage, this, &GUIHandler::ChangeImage);
}

void GUIHandler::Login(string username, string password)
{
	// SEND LOGIN PACKET

	// ON SUCCESS
	stackedWidget->SwitchView(GameWidgetView);

	// ON FAILURE
	// do something
}

void GUIHandler::CreateAccount(string username, string password, string firstname, string lastname)
{
	// SEND CREATE ACCOUNT PACKET

	// ON SUCCESS
	// show success popup

	// ON FAILURE
	// show :(
}

void GUIHandler::Logout()
{
	// SEND LOGOUT PACKET
}

void GUIHandler::MakeGameMove(ClickableLabel* label)
{
	// SEND GAME PACKET

	// ON SUCCESS
	QPixmap circle("assets/circle_sprite.png");
	label->setPixmap(circle);

}

void GUIHandler::ChangeImage(QPixmap image)
{
	// SEND IMAGE PACKET
}

void GUIHandler::SwitchView(WIDGET_VIEW_NAME name)
{
	stackedWidget->SwitchView(name);
}

StackedWidget* GUIHandler::GetStackedWidget()
{
	return this->stackedWidget;
}

GameWidget* GUIHandler::GetGameWidget()
{
	return this->gameWidget;
}

