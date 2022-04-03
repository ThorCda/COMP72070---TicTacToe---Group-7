/********************************************************************************
** Form generated from reading UI file 'LoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_10;
    QLabel *titleLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *usernameField;
    QLabel *usernameLabel;
    QGridLayout *gridLayout_3;
    QLineEdit *passwordField;
    QLabel *passwordLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *noAccountLabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *createAccountButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(720, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWidget->sizePolicy().hasHeightForWidth());
        LoginWidget->setSizePolicy(sizePolicy);
        LoginWidget->setMinimumSize(QSize(100, 0));
        LoginWidget->setAutoFillBackground(false);
        LoginWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(LoginWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 2, 1, 1);

        titleLabel = new QLabel(LoginWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy1);
        titleLabel->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setPointSize(26);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("margin-bottom:50px; margin-top:100px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        usernameField = new QLineEdit(LoginWidget);
        usernameField->setObjectName(QString::fromUtf8("usernameField"));
        sizePolicy.setHeightForWidth(usernameField->sizePolicy().hasHeightForWidth());
        usernameField->setSizePolicy(sizePolicy);
        usernameField->setMinimumSize(QSize(200, 0));
        QFont font1;
        font1.setPointSize(12);
        usernameField->setFont(font1);
        usernameField->setStyleSheet(QString::fromUtf8("margin-bottom:10px;"));

        gridLayout_2->addWidget(usernameField, 1, 0, 1, 1);

        usernameLabel = new QLabel(LoginWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(usernameLabel->sizePolicy().hasHeightForWidth());
        usernameLabel->setSizePolicy(sizePolicy2);
        usernameLabel->setFont(font1);
        usernameLabel->setAutoFillBackground(false);
        usernameLabel->setStyleSheet(QString::fromUtf8("background-color: none"));
        usernameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        usernameLabel->setMargin(0);

        gridLayout_2->addWidget(usernameLabel, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        passwordField = new QLineEdit(LoginWidget);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        sizePolicy.setHeightForWidth(passwordField->sizePolicy().hasHeightForWidth());
        passwordField->setSizePolicy(sizePolicy);
        passwordField->setMinimumSize(QSize(200, 0));
        passwordField->setFont(font1);
        passwordField->setStyleSheet(QString::fromUtf8("margin-bottom:20px;"));

        gridLayout_3->addWidget(passwordField, 1, 0, 1, 1);

        passwordLabel = new QLabel(LoginWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        sizePolicy2.setHeightForWidth(passwordLabel->sizePolicy().hasHeightForWidth());
        passwordLabel->setSizePolicy(sizePolicy2);
        passwordLabel->setFont(font1);
        passwordLabel->setAutoFillBackground(false);
        passwordLabel->setStyleSheet(QString::fromUtf8("background-color:none"));

        gridLayout_3->addWidget(passwordLabel, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        loginButton = new QPushButton(LoginWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy3);
        loginButton->setFont(font1);
        loginButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(loginButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        noAccountLabel = new QLabel(LoginWidget);
        noAccountLabel->setObjectName(QString::fromUtf8("noAccountLabel"));
        noAccountLabel->setFont(font1);
        noAccountLabel->setStyleSheet(QString::fromUtf8("margin-bottom:15px;"));
        noAccountLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(noAccountLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        createAccountButton = new QPushButton(LoginWidget);
        createAccountButton->setObjectName(QString::fromUtf8("createAccountButton"));
        createAccountButton->setFont(font1);

        horizontalLayout_3->addWidget(createAccountButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 0, 1, 1);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "LoginWidget", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWidget", "Tic-Tac-Toe Infinity 2.0", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginWidget", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWidget", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWidget", "Login", nullptr));
        noAccountLabel->setText(QCoreApplication::translate("LoginWidget", "Don't have an account?", nullptr));
        createAccountButton->setText(QCoreApplication::translate("LoginWidget", "Create Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
