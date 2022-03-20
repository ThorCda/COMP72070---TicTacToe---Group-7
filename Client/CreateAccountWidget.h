#pragma once

#include <QWidget>
#include "ui_CreateAccountWidget.h"

namespace Ui {
    class CreateAccountWidget;
}

class CreateAccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccountWidget(QWidget* parent = nullptr);
    ~CreateAccountWidget();


private slots:
    void on_backButton_clicked();

signals:
    void changeStackedWidgetIndex(int);
    void widgetChanged(int, int);

private:
    Ui::CreateAccountWidget* ui;
};
