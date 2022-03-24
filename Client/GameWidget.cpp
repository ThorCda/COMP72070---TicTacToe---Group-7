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
    ui->setupUi(this);

    setButtonCSS(ui->logoutButton);
    setButtonCSS(ui->accountButton);

    ui->accountButton->setFocusPolicy(Qt::NoFocus);
    ui->logoutButton->setFocusPolicy(Qt::NoFocus);

    QPixmap pixmap("circle_sprite.png");
    QPalette palette;
    palette.setBrush(ui->testButton->backgroundRole(), QBrush(pixmap));

    ui->testButton->setFlat(true);
    ui->testButton->setAutoFillBackground(true);
    ui->testButton->setPalette(palette);
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

void GameWidget::on_accountButton_clicked()
{
    emit changeStackedWidgetIndex(3);
    emit widgetChanged(720, 720);
    emit setLoginWidgetFocus();
}
