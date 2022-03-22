#pragma once

#include <QWidget>
#include "ui_AccountWidget.h"

namespace Ui {
	class AccountWidget;
}

class AccountWidget : public QWidget
{
	Q_OBJECT

public:
	AccountWidget(QWidget *parent = nullptr);
	~AccountWidget();

private:
	Ui::AccountWidget* ui;
};
