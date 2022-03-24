#include "Client/MainWindow.h"
#include "Client/LoginWidget.h"
#include "Client/GameWidget.h"
#include "Client/StackedWidget.h"
#include "Client/CreateAccountWidget.h"
#include "Client/AccountWidget.h"

#include <qstackedwidget.h>
#include <qmainwindow.h>
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MainWindow* mainWindow = new MainWindow();

    LoginWidget* loginWidget = new LoginWidget;
    GameWidget* gameWidget = new GameWidget;
    CreateAccountWidget* createAccountWidget = new CreateAccountWidget;
    AccountWidget* accountWidget = new AccountWidget;

    StackedWidget* stackedWidget = new StackedWidget();

    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(gameWidget);
    stackedWidget->addWidget(createAccountWidget);
    stackedWidget->addWidget(accountWidget);

    mainWindow->setCentralWidget(stackedWidget);

    QObject::connect(loginWidget, &LoginWidget::changeStackedWidgetIndex, stackedWidget, &StackedWidget::changeIndex);
    QObject::connect(loginWidget, &LoginWidget::widgetChanged, mainWindow, &MainWindow::resizeWindow);
    QObject::connect(loginWidget, &LoginWidget::setCreateAccountWidgetFocus, createAccountWidget, &CreateAccountWidget::setCreateAccountWidgetFocus);

    QObject::connect(gameWidget, &GameWidget::changeStackedWidgetIndex, stackedWidget, &StackedWidget::changeIndex);
    QObject::connect(gameWidget, &GameWidget::widgetChanged, mainWindow, &MainWindow::resizeWindow);
    QObject::connect(gameWidget, &GameWidget::setLoginWidgetFocus, loginWidget, &LoginWidget::setLoginWidgetFocus);

    QObject::connect(createAccountWidget, &CreateAccountWidget::changeStackedWidgetIndex, stackedWidget, &StackedWidget::changeIndex);
    QObject::connect(createAccountWidget, &CreateAccountWidget::widgetChanged, mainWindow, &MainWindow::resizeWindow);
    QObject::connect(createAccountWidget, &CreateAccountWidget::setLoginWidgetFocus, loginWidget, &LoginWidget::setLoginWidgetFocus);

    QObject::connect(accountWidget, &AccountWidget::changeStackedWidgetIndex, stackedWidget, &StackedWidget::changeIndex);
    QObject::connect(accountWidget, &AccountWidget::widgetChanged, mainWindow, &MainWindow::resizeWindow);

    

    mainWindow->show();
    mainWindow->resizeWindow(loginWidget->getWidth(), loginWidget->getHeight());

    return a.exec();
}
