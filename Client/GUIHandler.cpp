#include <string>
#include "GUIHandler.h"
#include "LoginWidget.h"
#include "GameWidget.h"

using namespace std;

GUIHandler::GUIHandler(LoginWidget* loginWidget, CreateAccountWidget* createAccountWidget, GameWidget* gameWidget, AccountWidget* accountWidget, StackedWidget* stackedWidget)
{
	this->loginWidget = loginWidget;
	this->createAccountWidget = createAccountWidget;
	this->gameWidget = gameWidget;
	this->accountWidget = accountWidget;
	this->stackedWidget = stackedWidget;
}


// Links Signals from all other widgets to Handler slots
void GUIHandler::SetupConnections()
{
	QObject::connect(loginWidget, &LoginWidget::Login, this, &GUIHandler::Login);
	QObject::connect(createAccountWidget, &CreateAccountWidget::CreateAccount, this, &GUIHandler::CreateAccount);
	QObject::connect(gameWidget, &GameWidget::Logout, this, &GUIHandler::Logout);
	QObject::connect(gameWidget, &GameWidget::SendGameMove, this, &GUIHandler::MakeGameMove);
	QObject::connect(accountWidget, &AccountWidget::ChangeImage, this, &GUIHandler::ChangeImage);
}

void GUIHandler::Login(string username, string password)
{
	// SEND LOGIN PACKET

}

void GUIHandler::CreateAccount(string username, string password, string firstname, string lastname)
{
	// SEND CREATE ACCOUNT PACKET

}

void GUIHandler::Logout()
{
	// SEND LOGOUT PACKET

}

void GUIHandler::MakeGameMove(int gridNum)
{
	// SEND GAME PACKET

}

void GUIHandler::ChangeImage(QPixmap image)
{
	// SEND IMAGE PACKET
}

