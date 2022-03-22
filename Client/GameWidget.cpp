#include "GameWidget.h"
#include "CSS.h"
#include "QtWidgets/qgraphicswidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>

GameWidget::GameWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{

    this->setFocusPolicy(Qt::NoFocus);
    ui->setupUi(this);

    this->setFocusPolicy(Qt::NoFocus);


    setButtonCSS(ui->logoutButton);
    setButtonCSS(ui->accountButton);

    ui->accountButton->setFocusPolicy(Qt::NoFocus);
    ui->logoutButton->setFocusPolicy(Qt::NoFocus);
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_logoutButton_clicked()
{
    emit changeStackedWidgetIndex(0);
    emit widgetChanged(720, 720);
    emit setLoginWidgetFocus();
}
