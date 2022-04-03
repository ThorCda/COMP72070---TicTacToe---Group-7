#include "LoginWidget.h"

using namespace std;

LoginWidget::LoginWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    QTimer::singleShot(0, ui->usernameField, SLOT(setFocus()));

    setButtonCSS(ui->loginButton);
    ui->loginButton->setFocusPolicy(Qt::NoFocus);

    setButtonCSS(ui->createAccountButton);
    ui->createAccountButton->setFocusPolicy(Qt::NoFocus);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}


void LoginWidget::on_loginButton_clicked()
{
    emit Login(getUsername(), getPassword());
    emit RequestImage();
    ui->passwordField->clear();
}


void LoginWidget::on_createAccountButton_clicked()
{
    emit SwitchView(CreateAccountWidgetView);
}

void LoginWidget::setLoginWidgetFocus()
{
    QTimer::singleShot(0, ui->usernameField, SLOT(setFocus()));
}

string LoginWidget::getUsername()
{
    return ui->usernameField->text().toStdString();
}

void LoginWidget::clearUsername()
{
    ui->usernameField->clear();
}

string LoginWidget::getPassword()
{
    return ui->passwordField->text().toStdString();
}

void LoginWidget::clearPassword()
{
    ui->passwordField->clear();
}


