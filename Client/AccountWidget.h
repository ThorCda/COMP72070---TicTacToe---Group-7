#pragma once

#include <QWidget>
#include "ui_AccountWidget.h"
#include "WidgetNames.h"
#include "../Server/Account.h"

namespace Ui {
	class AccountWidget;
}

class AccountWidget : public QWidget
{
	Q_OBJECT

public:
	AccountWidget(QWidget *parent = nullptr);
	~AccountWidget();
	void UpdateUI(Account*);

public slots:
	void on_changeImgButton_clicked();
	void on_backButton_2_clicked();

signals:
	void SwitchView(WidgetViewName);
	void changeStackedWidgetIndex(int);
	void widgetChanged(int, int);
	void ChangeImage(string);

private:
	Ui::AccountWidget* ui;
};
