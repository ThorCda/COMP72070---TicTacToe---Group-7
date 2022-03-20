#include "LoginWidget.h"
#include "QtWidgets/qgraphicseffect.h"

LoginWidget::LoginWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    QGraphicsEffect* effect = new QGraphicsBlurEffect(this);
    ui->menuBox->setGraphicsEffect(effect);

    QString cs1 = "QPushButton {"
        "align-items: center;"
        "background-color: #0A66C2;"
        "border: 0;"
        "border-radius: 50px;"
        "box-sizing: border-box;"
        "color: #ffffff;"
        "cursor: pointer;"
        "display: inline-flex;"
        "font-size: 16px;"
        "font-weight: 600;"
        "justify-content: center;"
        "line-height: 20px;"
        "max-width: 480px;"
        "min-height: 40px;"
        "min-width: 0px;"
        "overflow: hidden;"
        "padding: 0px;"
        "padding-left: 20px;"
        "padding-right: 20px;"
        "text-align: center;"
        "touch-action: manipulation;"
        "transition: background-color 0.167s cubic-bezier(0.4, 0, 0.2, 1) 0s, box-shadow 0.167s cubic-bezier(0.4, 0, 0.2, 1) 0s, color 0.167s cubic-bezier(0.4, 0, 0.2, 1) 0s;"
        "user-select: none;"
        "-webkit-user-select: none;"
        "vertical-align: middle;"
        "}"
        "QPushButton:hover,"
        "QPushButton:focus {"
        "background-color: #16437E;"
        "color: #ffffff;"
        "}";

        ui->loginButton->setStyleSheet(cs1);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

int LoginWidget::getWidth()
{
    return this->width;
}

int LoginWidget::getHeight()
{
    return this->height;
}


void LoginWidget::on_loginButton_clicked()
{
    emit changeStackedWidgetIndex(1);
    emit widgetChanged(1024, 576);
}


void LoginWidget::on_createAccountButton_clicked()
{
    emit changeStackedWidgetIndex(2);
    emit widgetChanged(500, 500);
}


