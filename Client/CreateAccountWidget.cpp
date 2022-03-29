#include "CreateAccountWidget.h"

using namespace std;

CreateAccountWidget::CreateAccountWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CreateAccountWidget)
{
    ui->setupUi(this);

    QTimer::singleShot(0, ui->firstnameField, SLOT(setFocus()));

    setButtonCSS(ui->backButton);
    ui->backButton->setFocusPolicy(Qt::NoFocus);

    setButtonCSS(ui->createAccountButton);    
    ui->createAccountButton->setFocusPolicy(Qt::NoFocus);

}

CreateAccountWidget::~CreateAccountWidget()
{
    delete ui;
}

string CreateAccountWidget::getUsername()
{
    return ui->usernameField->text().toStdString();
}

string CreateAccountWidget::getPassword()
{
    return ui->passwordField->text().toStdString();
}
string CreateAccountWidget::getFirstname()
{
    return ui->firstnameField->text().toStdString();
}
string CreateAccountWidget::getLastname()
{
    return ui->lastnameField->text().toStdString();
}

void CreateAccountWidget::clearFields()
{
    ui->firstnameField->clear();
    ui->lastnameField->clear();
    ui->usernameField->clear();
    ui->passwordField->clear();
}

void CreateAccountWidget::on_createAccountButton_clicked()
{
    emit CreateAccount(getUsername(), getPassword(), getFirstname(), getLastname());

    // LOGIC HERE FOR SUCCESS/FAILURE
}

void CreateAccountWidget::on_backButton_clicked()
{
    emit SwitchView(LoginWidgetView);
}

void CreateAccountWidget::setCreateAccountWidgetFocus()
{
    QTimer::singleShot(0, ui->firstnameField, SLOT(setFocus()));
}
