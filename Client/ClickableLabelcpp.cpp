
#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {


}

ClickableLabel::~ClickableLabel() {}

int ClickableLabel::getGridNum()
{
    return this->gridNum;
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked(this);
}