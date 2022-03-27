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

public slots:
	void on_changeImgButton_clicked();
	void on_backButton_2_clicked();

signals:
	void changeStackedWidgetIndex(int);
	void widgetChanged(int, int);
	void ChangeImage(QPixmap);

private:
	Ui::AccountWidget* ui;
};
