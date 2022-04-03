#pragma once
#include "NetworkHandler.h"
#include <QMainWindow>
#include "ui_MainWindow.h"
#include "GUIHandler.h"
#include "StackedWidget.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	void SetGUI(GUIHandler*);
	void SetNetworkHandler(NetworkHandler*);
	void SetupConnections();

public slots:
	void ResizeWindow(int, int);

public:
	Ui::MainWindow* ui;
	GUIHandler* gui;
	NetworkHandler* hdlr;
};
