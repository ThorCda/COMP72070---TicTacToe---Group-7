#pragma once

#include <QWidget>
//#include "QtWidgets/qgraphicswidget.h"
//#include <QtWidgets/QVBoxLayout>
//#include <QtWidgets/QHBoxLayout>
//#include <QtWidgets/QGridLayout>
#include <QTimer>
#include <string>

#include "ui_LoginWidget.h"
#include "CSS.h"
#include "WidgetNames.h"


namespace Ui { class LoginWidget; }

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget* parent = nullptr);
    ~LoginWidget();
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
    void SwitchView(WIDGET_VIEW_NAME);
    void setCreateAccountWidgetFocus();

private:
    Ui::LoginWidget* ui;
};
