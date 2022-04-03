#pragma once

#include <QWidget>
#include <qstackedwidget.h>
#include <qmainwindow.h>
#include <QtWidgets/QApplication>
#include <qpixmap.h>
#include <iostream>

#include "LoginWidget.h"
#include "CreateAccountWidget.h"
#include "GameWidget.h"
#include "AccountWidget.h"
#include "StackedWidget.h"
#include "WidgetNames.h"
#include "ClickableLabel.h"
#include "../Server/Account.h"

using namespace std;

class GUIHandler : public QWidget {
	Q_OBJECT
private:
	LoginWidget* loginWidget;
	CreateAccountWidget* createAccountWidget;
	GameWidget* gameWidget;
	AccountWidget* accountWidget;
	StackedWidget* stackedWidget;
	Account* account;

	ClickableLabel* currentMove;

	void SetupConnections();

public slots:
	void SwitchView(WIDGET_VIEW_NAME);
	void NewGame();

	// Network plugins
	void Login(string, string);
	void LOGIN_SUCCESS(Account*);
	void LOGIN_FAILURE();
	void UPDATE_GAME_BOARD(int);
	void GAME_STATUS(int);
	//void IMAGE_RECIEVED();


	void CreateAccount(string, string, string, string);
	void Logout();
	void MakeGameMove(ClickableLabel*);
	void ChangeImage(string);
	void RequestImage();

signals:
	//void START_CONNECTION();
	//void STOP_CONNECTION();
	void LOGIN(char*, char*);
	void LOGOUT();
	void GAME_MOVE(int);
	void CREATE_ACCOUNT(char*, char*, char*, char*);
	void SEND_IMAGE(string);
	void REQUEST_IMAGE();

public:
	GUIHandler();
	StackedWidget* GetStackedWidget();
	GameWidget* GetGameWidget();
};

