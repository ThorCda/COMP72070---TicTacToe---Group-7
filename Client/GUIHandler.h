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
	void SwitchView(WIDGET_VIEW_NAME);

	// Network plugins
	void Login(string, string);
	void CreateAccount(string, string, string, string);
	void Logout();
	void MakeGameMove(ClickableLabel*);
	void ChangeImage(QPixmap);

public:
	GUIHandler();
	StackedWidget* GetStackedWidget();
	GameWidget* GetGameWidget();
};
