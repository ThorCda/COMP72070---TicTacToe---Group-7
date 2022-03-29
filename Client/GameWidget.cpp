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
