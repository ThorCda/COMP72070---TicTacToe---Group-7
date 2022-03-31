#pragma once

#include <QWidget>
#include <qstackedwidget.h>
#include <qmainwindow.h>
#include <QtWidgets/QApplication>
#include <qpixmap.h>

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

	void CreateAccount(string, string, string, string);
	void Logout();
	void MakeGameMove(ClickableLabel*);
	void ChangeImage(QPixmap);

signals:
	void LOGIN();
	void GAME_MOVE(int);

public:
	GUIHandler();
	StackedWidget* GetStackedWidget();
	GameWidget* GetGameWidget();

};

