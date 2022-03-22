#include "StackedWidget.h"
#include <qwidget.h>

StackedWidget::StackedWidget()
{
}

StackedWidget::~StackedWidget()
{

}

void StackedWidget::changeIndex(int newIndex)
{
    this->setCurrentIndex(newIndex);
}
