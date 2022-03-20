#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setStyleSheet("background-color: white");
    QList<QToolBar*> allToolBars = this->findChildren<QToolBar*>();
    foreach(QToolBar * tb, allToolBars) {
        // This does not delete the tool bar.
        this->removeToolBar(tb);
    }
    ui->setupUi(this);
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
