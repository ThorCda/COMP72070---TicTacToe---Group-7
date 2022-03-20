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


signals:
    void changeStackedWidgetIndex(int);
    void widgetChanged(int, int);

private:
    Ui::LoginWidget* ui;
    static const int height{ 500 };
    static const int width{ 500 };
};
