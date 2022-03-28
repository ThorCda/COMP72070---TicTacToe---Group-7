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

    // Remove top/bottom tool bars
    QList<QToolBar*> allToolBars = this->findChildren<QToolBar*>();
    foreach(QToolBar * tb, allToolBars) {
        this->removeToolBar(tb);
    }

    ui->setupUi(this);

    // Place Window in center screen
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->availableGeometry();
    int height = screenGeometry.height()/2 - 360;
    int width = screenGeometry.width()/2 - 360;
    this->move(QPoint(width, height));

    ResizeWindow(720, 720);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ResizeWindow(int width, int height)
{
    resize(width, height);
    setFixedSize(width, height);
}

void MainWindow::SetGUI(GUIHandler* gui)
{
    this->gui = gui;

    // Set the GUI Handler for the Window
    this->setCentralWidget(gui->GetStackedWidget());

    // Connect changing stacked widget signal to resize window slot
    QObject::connect(gui->GetStackedWidget(), &StackedWidget::ResizeWindow, this, &MainWindow::ResizeWindow);
}
