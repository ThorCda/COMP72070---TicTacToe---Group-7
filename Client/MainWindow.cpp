#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <qwidget.h>
#include <qscreen.h>
#include <QApplication>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setStyleSheet("background-color: white");
    QList<QToolBar*> allToolBars = this->findChildren<QToolBar*>();
    foreach(QToolBar * tb, allToolBars) {
        this->removeToolBar(tb);
    }
    ui->setupUi(this);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->availableGeometry();
    int height = screenGeometry.height()/2 - 360;
    int width = screenGeometry.width()/2 - 360;

    this->move(QPoint(width, height));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeWindow(int width, int height)
{
    this->resize(width, height);
    this->setFixedSize(width, height);
}
