#pragma once

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();
    void ChangePixmap();
    int GetGridNum();

signals:
    void clicked(ClickableLabel*);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    int gridNum;
};
