#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
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
    emit changeStackedWidgetIndex(1);
    emit widgetChanged(1024, 576);
}


void LoginWidget::on_createAccountButton_clicked()
{
    emit changeStackedWidgetIndex(2);
    emit widgetChanged(500, 500);
}


