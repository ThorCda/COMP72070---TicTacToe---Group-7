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


public slots:
    void on_backButton_clicked();
    void setCreateAccountWidgetFocus();

signals:
    void changeStackedWidgetIndex(int);
    void widgetChanged(int, int);
    void setLoginWidgetFocus();

private:
    Ui::CreateAccountWidget* ui;
};
