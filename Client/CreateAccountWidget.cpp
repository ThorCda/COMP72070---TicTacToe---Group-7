#include <QTimer>
#include "QtWidgets/qgraphicswidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include "CreateAccountWidget.h"
#include "CSS.h"

CreateAccountWidget::CreateAccountWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CreateAccountWidget)
{
    ui->setupUi(this);

    QTimer::singleShot(0, ui->firstnameField, SLOT(setFocus()));

    setButtonCSS(ui->backButton);
    ui->backButton->setFocusPolicy(Qt::NoFocus);

    setButtonCSS(ui->createAccountButton);    
    ui->createAccountButton->setFocusPolicy(Qt::NoFocus);

}

CreateAccountWidget::~CreateAccountWidget()
{
    delete ui;
}

void CreateAccountWidget::on_backButton_clicked()
{
    emit setLoginWidgetFocus();
    emit changeStackedWidgetIndex(0);
    emit widgetChanged(720, 720);
}

void CreateAccountWidget::setCreateAccountWidgetFocus()
{
    QTimer::singleShot(0, ui->firstnameField, SLOT(setFocus()));
}
