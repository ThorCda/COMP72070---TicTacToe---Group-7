#pragma once

#include <QWidget>
#include <string>
#include "ui_GameWidget.h"
#include "ClickableLabel.h"

namespace Ui {
    class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    int width = 1024;
    int height = 576;
    GameWidget(QWidget* parent = nullptr);
    ~GameWidget();

signals:
    void changeStackedWidgetIndex(int);
    void widgetChanged(int, int);
    void setLoginWidgetFocus();
    void Logout();
    void SendGameMove(int);

public slots:
    void on_logoutButton_clicked();
    void on_accountButton_clicked();
    void on_newGameButton_clicked();

private slots:
    void on_gameBoardLabel_clicked(ClickableLabel*);

private:
    Ui::GameWidget* ui;
};
