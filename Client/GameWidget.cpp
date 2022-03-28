//#include "CSS.h"
//#include "QtWidgets/qgraphicswidget.h"
//#include <QtWidgets/QVBoxLayout>
//#include <QtWidgets/QHBoxLayout>
//#include <QtWidgets/QGridLayout>
//#include <QPixmap>
//#include <string>
//#include "ClickableLabel.h"
//#include <qwidget.h>
//#include "StackedWidget.h"
//#include <QPixMap>
#include "GameWidget.h"


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

    // Don't @ me about for loops because it doesn't work
    /*QObject::connect(ui->topLeft, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);*/
    /*QObject::connect(ui->topMiddle, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->topRight, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->middleLeft, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->middle, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->middleRight, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->bottomLeft, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->bottomMiddle, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);
    QObject::connect(ui->bottomRight, &ClickableLabel::clicked, this, &GameWidget::on_gameBoardLabel_clicked);*/
    
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_logoutButton_clicked()
{
    SwitchView(LoginWidgetView);
    emit Logout();
    //emit setLoginWidgetFocus();
}

void GameWidget::on_accountButton_clicked()
{
    SwitchView(AccountWidgetView);
    //emit setLoginWidgetFocus();
}

//void GameWidget::on_gameBoardLabel_clicked(ClickableLabel* label)
//{
//    //emit SendGameMove(label->getGridNum());
//
//    // LOGIC MISSING HERE FOR GOOD/BAD MOVES
//
//    /*QPixmap circle("assets/circle_sprite.png");
//    label->setPixmap(circle);*/
//}

void GameWidget::on_newGameButton_clicked()
{
    // Don't @ me about for loops here either!
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
}

Ui::GameWidget* GameWidget::GetGameWidgetUI()
{
    return ui;
}
