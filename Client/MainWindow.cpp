#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <qwidget.h>
#include <qscreen.h>
#include <QApplication>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Remove top/bottom tool bars
    QList<QToolBar*> allToolBars = this->findChildren<QToolBar*>();
    foreach(QToolBar * tb, allToolBars) {
        this->removeToolBar(tb);
    }

    ui->setupUi(this);
    this->setStyleSheet("background-color:white;");

    // Place Window in center screen
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->availableGeometry();
    int height = screenGeometry.height()/2 - 360;
    int width = screenGeometry.width()/2 - 360;
    this->move(QPoint(width, height));

    ResizeWindow(720, 720);

    SetGUI(new GUIHandler());
    SetNetworkHandler(new NetworkHandler());

    SetupConnections();
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

void MainWindow::closeEvent(QCloseEvent *bar) {
    bar->ignore();
}

void MainWindow::SetGUI(GUIHandler* gui)
{
    this->gui = gui;

    // Set the GUI Handler for the Window
    this->setCentralWidget(gui->GetStackedWidget());

    // Connect changing stacked widget signal to resize window slot
    QObject::connect(gui->GetStackedWidget(), &StackedWidget::ResizeWindow, this, &MainWindow::ResizeWindow);
}

void MainWindow::SetNetworkHandler(NetworkHandler* hdlr)
{
    this->hdlr = hdlr;
}

void MainWindow::SetupConnections()
{
    QObject::connect(this->gui, &GUIHandler::LOGIN, this->hdlr, &NetworkHandler::LOGIN);
    QObject::connect(this->hdlr, &NetworkHandler::LOGIN_SUCCESS, this->gui, &GUIHandler::LOGIN_SUCCESS);
    QObject::connect(this->hdlr, &NetworkHandler::LOGIN_FAILURE, this->gui, &GUIHandler::LOGIN_FAILURE);
    QObject::connect(this->gui, &GUIHandler::LOGOUT, this->hdlr, &NetworkHandler::LOGOUT);
        
    //QObject::connect(this->hdlr, &NetworkHandler::IMAGE_RECIEVED, this->gui, &GUIHandler::IMAGE_RECIEVED);

    QObject::connect(this->gui, &GUIHandler::CREATE_ACCOUNT, this->hdlr, &NetworkHandler::CREATE_ACCOUNT);

    QObject::connect(this->gui, &GUIHandler::GAME_MOVE, this->hdlr, &NetworkHandler::GAME_MOVE);
    QObject::connect(this->hdlr, &NetworkHandler::UPDATE_GAME_BOARD, this->gui, &GUIHandler::UPDATE_GAME_BOARD);
    QObject::connect(this->hdlr, &NetworkHandler::GAME_STATUS, this->gui, &GUIHandler::GAME_STATUS);

    QObject::connect(this->gui, &GUIHandler::SEND_IMAGE, this->hdlr, &NetworkHandler::SEND_IMAGE);
    QObject::connect(this->gui, &GUIHandler::REQUEST_IMAGE, this->hdlr, &NetworkHandler::REQUEST_IMAGE);

}
