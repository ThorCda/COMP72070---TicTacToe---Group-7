#include "AccountWidget.h"
#include "CSS.h"
#include "QtWidgets/qgraphicswidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>

AccountWidget::AccountWidget(QWidget *parent):
	QWidget(parent),
	ui(new Ui::AccountWidget)
{
	ui->setupUi(this);

	setButtonCSS(ui->backButton_2);
	setButtonCSS(ui->changeImgButton);

	ui->backButton_2->setFocusPolicy(Qt::NoFocus);
	ui->changeImgButton->setFocusPolicy(Qt::NoFocus);
}

AccountWidget::~AccountWidget()
{


}
