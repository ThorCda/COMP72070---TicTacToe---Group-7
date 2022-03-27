#pragma once

#include <QWidget>
#include "ui_LoginWidget.h"
#include <string>

namespace Ui { class LoginWidget; }

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget* parent = nullptr);
    ~LoginWidget();
    int getWidth();
    int getHeight();
    std::string getUsername();
    void clearUsername();
    std::string getPassword();
    void clearPassword();

public slots:
    void on_loginButton_clicked();
    void on_createAccountButton_clicked();
    void setLoginWidgetFocus();


signals:
    void Login(std::string, std::string);
    void changeStackedWidgetIndex(int);
    void widgetChanged(int, int);
    void setCreateAccountWidgetFocus();

private:
    Ui::LoginWidget* ui;
    static const int height{ 720 };
    static const int width{ 720 };
};
