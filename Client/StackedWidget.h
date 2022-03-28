#pragma once

#include <QStackedWidget>
#include "ui_StackedWidget.h"
#include "LoginWidget.h"
#include "GameWidget.h"
#include "CreateAccountWidget.h"
#include "AccountWidget.h"
#include "WidgetNames.h"

class StackedWidget : public QStackedWidget
{
	Q_OBJECT

public:
	StackedWidget();
	StackedWidget(LoginWidget*, CreateAccountWidget*, GameWidget*, AccountWidget*);
	~StackedWidget();
	void SwitchView(WIDGET_VIEW_NAME);

signals:
	void ResizeWindow(int, int);
};
