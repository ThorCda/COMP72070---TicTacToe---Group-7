#pragma once

#include <QWidget>
#include "LoginWidget.h"
#include "CreateAccountWidget.h"
#include "GameWidget.h"
#include "AccountWidget.h"
#include "StackedWidget.h"

using namespace std;

class GUIHandler : public QWidget {

private:
	LoginWidget* loginWidget;
	CreateAccountWidget* createAccountWidget;
	GameWidget* gameWidget;
	AccountWidget* accountWidget;
	StackedWidget* stackedWidget;

	void SetupConnections();

public slots:
	void SwitchView();

	// Network plugins
	void Login(string, string);
	void CreateAccount(string, string, string, string);
	void Logout();
	void MakeGameMove(int);
	void ChangeImage(QPixmap);

public:
	GUIHandler(LoginWidget*, CreateAccountWidget*, GameWidget*, AccountWidget*, StackedWidget*);
};

