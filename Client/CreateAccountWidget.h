#pragma once

#include <QWidget>
#include "ui_CreateAccountWidget.h"

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
    void CreateAccount(string, string, string, string);
    void changeStackedWidgetIndex(int);
    void widgetChanged(int, int);
    void setLoginWidgetFocus();

private:
    Ui::CreateAccountWidget* ui;
};
