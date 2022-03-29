
#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {


}

ClickableLabel::~ClickableLabel() {}

int ClickableLabel::GetGridNum()
{
    return gridNum;
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked(this);
}