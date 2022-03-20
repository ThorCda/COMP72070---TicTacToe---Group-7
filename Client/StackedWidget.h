#pragma once

#include <QStackedWidget>
#include "ui_StackedWidget.h"

class StackedWidget : public QStackedWidget
{
	Q_OBJECT

public:
	StackedWidget();
	~StackedWidget();

public slots:
	void changeIndex(int);
};
