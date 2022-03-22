#pragma once

#include <QWidget>
#include "ui_LoginWidget.h"

namespace Ui { class LoginWidget; }

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget* parent = nullptr);
    ~LoginWidget();
    int getWidth();
    int getHeight();

public slots:
    void on_loginButton_clicked();
    void on_createAccountButton_clicked();
    void setLoginWidgetFocus();


signals:
    void changeStackedWidgetIndex(int);
    void widgetChanged(int, int);
    void setCreateAccountWidgetFocus();

private:
    Ui::LoginWidget* ui;
    static const int height{ 720 };
    static const int width{ 720 };
};
