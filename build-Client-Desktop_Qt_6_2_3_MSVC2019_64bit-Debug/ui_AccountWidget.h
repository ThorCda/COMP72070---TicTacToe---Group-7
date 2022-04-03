/********************************************************************************
** Form generated from reading UI file 'AccountWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTWIDGET_H
#define UI_ACCOUNTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *backButton_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_7;
    QLabel *usernameField_2;
    QLabel *lastnameField_2;
    QLabel *lastnameLabel_2;
    QLabel *firstnameField_2;
    QLabel *usernameLabel_2;
    QLabel *firstnameLabel_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *playerImg;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *changeImgButton;
    QLabel *accountTitleLabel;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *AccountWidget)
    {
        if (AccountWidget->objectName().isEmpty())
            AccountWidget->setObjectName(QString::fromUtf8("AccountWidget"));
        AccountWidget->resize(720, 720);
        gridLayout = new QGridLayout(AccountWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 4, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        backButton_2 = new QPushButton(AccountWidget);
        backButton_2->setObjectName(QString::fromUtf8("backButton_2"));

        gridLayout_8->addWidget(backButton_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_3, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_8, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(20);
        usernameField_2 = new QLabel(AccountWidget);
        usernameField_2->setObjectName(QString::fromUtf8("usernameField_2"));
        QFont font;
        font.setPointSize(18);
        usernameField_2->setFont(font);
        usernameField_2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(usernameField_2, 2, 1, 1, 1);

        lastnameField_2 = new QLabel(AccountWidget);
        lastnameField_2->setObjectName(QString::fromUtf8("lastnameField_2"));
        lastnameField_2->setFont(font);
        lastnameField_2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lastnameField_2, 1, 1, 1, 1);

        lastnameLabel_2 = new QLabel(AccountWidget);
        lastnameLabel_2->setObjectName(QString::fromUtf8("lastnameLabel_2"));
        lastnameLabel_2->setFont(font);

        gridLayout_7->addWidget(lastnameLabel_2, 1, 0, 1, 1);

        firstnameField_2 = new QLabel(AccountWidget);
        firstnameField_2->setObjectName(QString::fromUtf8("firstnameField_2"));
        firstnameField_2->setFont(font);
        firstnameField_2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(firstnameField_2, 0, 1, 1, 1);

        usernameLabel_2 = new QLabel(AccountWidget);
        usernameLabel_2->setObjectName(QString::fromUtf8("usernameLabel_2"));
        usernameLabel_2->setFont(font);

        gridLayout_7->addWidget(usernameLabel_2, 2, 0, 1, 1);

        firstnameLabel_2 = new QLabel(AccountWidget);
        firstnameLabel_2->setObjectName(QString::fromUtf8("firstnameLabel_2"));
        firstnameLabel_2->setFont(font);

        gridLayout_7->addWidget(firstnameLabel_2, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_5, 3, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_6, 3, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 20);
        playerImg = new QLabel(AccountWidget);
        playerImg->setObjectName(QString::fromUtf8("playerImg"));
        playerImg->setMinimumSize(QSize(240, 240));
        playerImg->setMaximumSize(QSize(240, 240));
        playerImg->setLayoutDirection(Qt::LeftToRight);
        playerImg->setStyleSheet(QString::fromUtf8(""));
        playerImg->setFrameShape(QFrame::Box);
        playerImg->setScaledContents(true);
        playerImg->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(playerImg);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        changeImgButton = new QPushButton(AccountWidget);
        changeImgButton->setObjectName(QString::fromUtf8("changeImgButton"));

        horizontalLayout_4->addWidget(changeImgButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 1, 4, 1, 1);

        accountTitleLabel = new QLabel(AccountWidget);
        accountTitleLabel->setObjectName(QString::fromUtf8("accountTitleLabel"));
        QFont font1;
        font1.setPointSize(26);
        accountTitleLabel->setFont(font1);
        accountTitleLabel->setStyleSheet(QString::fromUtf8("margin-bottom:50px; margin-top:100px;"));
        accountTitleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(accountTitleLabel, 0, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 4, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 0, 1, 1);


        retranslateUi(AccountWidget);

        QMetaObject::connectSlotsByName(AccountWidget);
    } // setupUi

    void retranslateUi(QWidget *AccountWidget)
    {
        AccountWidget->setWindowTitle(QCoreApplication::translate("AccountWidget", "AccountWidget", nullptr));
        backButton_2->setText(QCoreApplication::translate("AccountWidget", "< Back", nullptr));
        usernameField_2->setText(QCoreApplication::translate("AccountWidget", "Nikolai_YT_TV", nullptr));
        lastnameField_2->setText(QCoreApplication::translate("AccountWidget", "Tictactonikov", nullptr));
        lastnameLabel_2->setText(QCoreApplication::translate("AccountWidget", "Last name:", nullptr));
        firstnameField_2->setText(QCoreApplication::translate("AccountWidget", "Nikolai", nullptr));
        usernameLabel_2->setText(QCoreApplication::translate("AccountWidget", "User name:", nullptr));
        firstnameLabel_2->setText(QCoreApplication::translate("AccountWidget", "First name:", nullptr));
        playerImg->setText(QString());
        changeImgButton->setText(QCoreApplication::translate("AccountWidget", "Change Image", nullptr));
        accountTitleLabel->setText(QCoreApplication::translate("AccountWidget", "Account Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountWidget: public Ui_AccountWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTWIDGET_H
