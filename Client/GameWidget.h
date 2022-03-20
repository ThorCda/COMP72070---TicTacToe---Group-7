#pragma once

#include <QWidget>
#include "ui_GameWidget.h"

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

private slots:
    void on_logoutButton_clicked();

private:
    Ui::GameWidget* ui;
};
