#include "CSS.h"
#include "QtWidgets/qgraphicswidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QPixmap>
#include "ClickableLabel.h"
#include <qwidget.h>
#include "GameWidget.h"
#include <QPixMap>

GameWidget::GameWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    setButtonCSS(ui->logoutButton);
    setButtonCSS(ui->accountButton);
    setButtonCSS(ui->newGameButton);

    ui->accountButton->setFocusPolicy(Qt::NoFocus);
    ui->logoutButton->setFocusPolicy(Qt::NoFocus);
    ui->newGameButton->setFocusPolicy(Qt::NoFocus);

    QObject::connect(ui->topLeft, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->topMiddle, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->topRight, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->middleLeft, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->middle, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->middleRight, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->bottomLeft, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->bottomMiddle, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->bottomRight, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    
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

void GameWidget::on_gameBoardLabel_clicked(ClickableLabel* label)
{
    QPixmap circle("assets/circle_sprite.png");
    label->setPixmap(circle);
}

void GameWidget::on_newGameButton_clicked()
{
    QPixmap blank;
    ui->topLeft->setPixmap(blank);
    ui->topMiddle->setPixmap(blank);
    ui->topRight->setPixmap(blank);
    ui->middleLeft->setPixmap(blank);
    ui->middle->setPixmap(blank);
    ui->middleRight->setPixmap(blank);
    ui->bottomLeft->setPixmap(blank);
    ui->bottomMiddle->setPixmap(blank);
    ui->bottomRight->setPixmap(blank);
    /*for (int i = 0; i < ui->gameBoard->count(); ++i)
    {
        ClickableLabel* widget = &(ClickableLabel)ui->gameBoard->itemAt(i)->widget();
        QPixmap blank;
        widget->setPixmap(blank);
    }*/
}
