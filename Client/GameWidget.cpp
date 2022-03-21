#include "GameWidget.h"

GameWidget::GameWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

}

GameWidget::~GameWidget()
{
    delete ui;
}


void GameWidget::on_logoutButton_clicked()
{
    emit changeStackedWidgetIndex(0);
    emit widgetChanged(720, 720);
    emit resetLoginWidgetCSS();
}
