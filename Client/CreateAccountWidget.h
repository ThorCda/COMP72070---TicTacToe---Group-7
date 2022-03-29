#pragma once

#include <QWidget>
#include <QTimer>

#include "ui_CreateAccountWidget.h"
#include "WidgetNames.h"
#include "CSS.h"

using namespace std;

namespace Ui {
    class CreateAccountWidget;
}

class CreateAccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccountWidget(QWidget* parent = nullptr);
    ~CreateAccountWidget();
    string getUsername();
    string getPassword();
    string getFirstname();
    string getLastname();
    void clearFields();


public slots:
    void on_backButton_clicked();
    void on_createAccountButton_clicked();
    void setCreateAccountWidgetFocus();

signals:
    void SwitchView(WIDGET_VIEW_NAME);
    void CreateAccount(string, string, string, string);
    void setLoginWidgetFocus();

private:
    Ui::CreateAccountWidget* ui;
};
