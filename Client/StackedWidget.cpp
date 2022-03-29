#include "StackedWidget.h"

StackedWidget::StackedWidget()
{

}

StackedWidget::StackedWidget(LoginWidget* loginWidget, CreateAccountWidget* createAccountWidget, GameWidget* gameWidget, AccountWidget* accountWidget)
{
    addWidget(loginWidget);
    addWidget(createAccountWidget);
    addWidget(gameWidget);
    addWidget(accountWidget);
}

StackedWidget::~StackedWidget()
{

}

void StackedWidget::SwitchView(WIDGET_VIEW_NAME name)
{
    if (name == LoginWidgetView)
    {
        setCurrentIndex(0);
        emit ResizeWindow(720, 720);
    }
    else if (name == CreateAccountWidgetView)
    {
        setCurrentIndex(1);
        emit ResizeWindow(720, 720);
    }
    else if (name == GameWidgetView)
    {
        setCurrentIndex(2);
        emit ResizeWindow(1280, 720);
    }
    else if (name == AccountWidgetView)
    {
        setCurrentIndex(3);
        emit ResizeWindow(720, 720);
    }
}
