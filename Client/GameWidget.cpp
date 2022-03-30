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

    InitGameBoard();
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_logoutButton_clicked()
{
    emit SwitchView(LoginWidgetView);
    emit Logout();
}

void GameWidget::on_accountButton_clicked()
{
    emit SwitchView(AccountWidgetView);
}

void GameWidget::on_newGameButton_clicked()
{
    emit NewGame();
}

Ui::GameWidget* GameWidget::GetGameWidgetUI()
{
    return ui;
}

//void GameWidget::SetLabelGridNums()
//{
//
//    for (int i = 1; i < 10; i++)
//    {
//        gameLabels[i]->SetGridNum(i);
//    }
//}

void GameWidget::InitGameBoard()
{
    gameLabels[0] = NULL;

    QPixmap blank;

    for (int i = 1; i < 10; i++)
    {
        gameLabels[i]->SetGridNum(i);
        gameLabels[i]->setPixmap(blank);
    }
}

void GameWidget::UpdateStats(Account* account)
{
    ui->winsCounter->setText(QString::number(account->getWins()));
    ui->lossesCounter->setText(QString::number(account->getLoses()));
    ui->drawsCounter->setText(QString::number(account->getDraws()));
}