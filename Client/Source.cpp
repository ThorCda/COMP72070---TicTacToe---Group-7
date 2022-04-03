#include "MainWindow.h"
#include "LoginWidget.h"
#include "GameWidget.h"
#include "StackedWidget.h"
#include "CreateAccountWidget.h"
#include "AccountWidget.h"
#include "GUIHandler.h"
#include "WidgetNames.h"

#include <qstackedwidget.h>
#include <qmainwindow.h>
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{

    QApplication a(argc, argv);

    MainWindow* mainWindow = new MainWindow();

    mainWindow->show();

    return a.exec();
}
