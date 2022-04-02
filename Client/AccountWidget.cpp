#include "AccountWidget.h"
#include "CSS.h"
#include "QtWidgets/qgraphicswidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QFileDialog>

using namespace std;

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
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Open Image"), ".", tr("Image Files (*.jpg)"));

	ui->playerImg->setPixmap(filename);

	string file = filename.toStdString();

	emit ChangeImage(file);
}

void AccountWidget::on_backButton_2_clicked()
{
	emit SwitchView(GameWidgetView);
}

void AccountWidget::UpdateUI(Account* account)
{
	ui->firstnameField_2->setText(QString::fromStdString(account->getFirstName()));
	ui->lastnameField_2->setText(QString::fromStdString(account->getLastName()));
	ui->usernameField_2->setText(QString::fromStdString(account->getUserName()));
}

void AccountWidget::UpdateImage()
{
	QPixmap x("Avatar.jpg");
	ui->playerImg->setPixmap(x);
}
