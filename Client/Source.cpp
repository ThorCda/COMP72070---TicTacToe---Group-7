#include "Client/MainWindow.h"
#include "Client/LoginWidget.h"
#include "Client/GameWidget.h"
#include "Client/StackedWidget.h"
#include "Client/CreateAccountWidget.h"
#include "Client/AccountWidget.h"
#include "Client/GUIHandler.h"
#include "Client/WidgetNames.h"

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
