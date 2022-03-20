#include "CreateAccountWidget.h"

CreateAccountWidget::CreateAccountWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CreateAccountWidget)
{
    ui->setupUi(this);
}

CreateAccountWidget::~CreateAccountWidget()
{
    delete ui;
}



void CreateAccountWidget::on_backButton_clicked()
{
    emit changeStackedWidgetIndex(0);
    emit widgetChanged(500, 500);
}
