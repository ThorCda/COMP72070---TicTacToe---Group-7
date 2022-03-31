#pragma once

#include <QWidget>
#include <QPixMap>
#include <string>

#include "ui_GameWidget.h"
#include "ClickableLabel.h"
#include "WidgetNames.h"
#include "CSS.h"
#include "../Server/Account.h"

namespace Ui {
    class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    ClickableLabel* gameLabels[10];

    GameWidget(QWidget* parent = nullptr);
    void InitGameBoard();
    ~GameWidget();
    Ui::GameWidget* GetGameWidgetUI();
    void UpdateStats(Account*);
    void disableGameBoard();
    void enableGameBoard();


signals:
    void SwitchView(WIDGET_VIEW_NAME);
    void Logout();
    void NewGame();
    void setLoginWidgetFocus();

public slots:
    void on_logoutButton_clicked();
    void on_accountButton_clicked();
    void on_newGameButton_clicked();

private:
    Ui::GameWidget* ui;
};
