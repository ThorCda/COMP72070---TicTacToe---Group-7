/********************************************************************************
** Form generated from reading UI file 'StackedWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKEDWIDGET_H
#define UI_STACKEDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>

QT_BEGIN_NAMESPACE

class Ui_StackedWidget
{
public:

    void setupUi(QStackedWidget *StackedWidget)
    {
        if (StackedWidget->objectName().isEmpty())
            StackedWidget->setObjectName(QString::fromUtf8("StackedWidget"));
        StackedWidget->resize(400, 300);

        retranslateUi(StackedWidget);

        QMetaObject::connectSlotsByName(StackedWidget);
    } // setupUi

    void retranslateUi(QStackedWidget *StackedWidget)
    {
        StackedWidget->setWindowTitle(QCoreApplication::translate("StackedWidget", "StackedWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StackedWidget: public Ui_StackedWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKEDWIDGET_H
