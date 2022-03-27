#include "LoginWidget.h"
#include "CSS.h"
#include "QtWidgets/qgraphicswidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QTimer>
#include <string>

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

int LoginWidget::getWidth()
{
    return this->width;
}

int LoginWidget::getHeight()
{
    return this->height;
}


void LoginWidget::on_loginButton_clicked()
{
    emit Login(getUsername(), getPassword());

    ui->usernameField->clear();

    // logic here
    emit changeStackedWidgetIndex(1);
    emit widgetChanged(1280, 720);
}


void LoginWidget::on_createAccountButton_clicked()
{
    emit changeStackedWidgetIndex(2);
    emit widgetChanged(720, 720);
    emit setCreateAccountWidgetFocus();
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
    ui->usernameField->clear();
}


