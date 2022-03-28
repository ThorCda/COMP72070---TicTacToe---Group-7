#pragma once

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

public slots:
	void ResizeWindow(int, int);

private:
	Ui::MainWindow* ui;
	GUIHandler* gui;
};
