#include "AccountWidget.h"
#include "CSS.h"
#include "QtWidgets/qgraphicswidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QFileDialog>

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

void AccountWidget::on_changeImgButton_clicked()
{
	auto fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));

	ui->playerImg->setPixmap(fileName);

	emit ChangeImage(ui->playerImg->pixmap());
}

void AccountWidget::on_backButton_2_clicked()
{
	emit changeStackedWidgetIndex(1);
	emit widgetChanged(1280, 720);
}
