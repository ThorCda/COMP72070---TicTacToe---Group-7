/********************************************************************************
** Form generated from reading UI file 'CreateAccountWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNTWIDGET_H
#define UI_CREATEACCOUNTWIDGET_H

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

class Ui_CreateAccountWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *firstnameLabel;
    QLineEdit *firstnameField;
    QGridLayout *gridLayout_3;
    QLabel *lastnameLabel;
    QLineEdit *lastnameField;
    QGridLayout *gridLayout_4;
    QLabel *usernameLabel;
    QLineEdit *usernameField;
    QGridLayout *gridLayout_5;
    QLabel *passwordLabel;
    QLineEdit *passwordField;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *createAccountButton;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CreateAccountWidget)
    {
        if (CreateAccountWidget->objectName().isEmpty())
            CreateAccountWidget->setObjectName(QString::fromUtf8("CreateAccountWidget"));
        CreateAccountWidget->resize(720, 720);
        gridLayout = new QGridLayout(CreateAccountWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        titleLabel = new QLabel(CreateAccountWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        titleLabel->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setPointSize(26);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("margin-bottom:50px; margin-top:100px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(145, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 52, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        firstnameLabel = new QLabel(CreateAccountWidget);
        firstnameLabel->setObjectName(QString::fromUtf8("firstnameLabel"));
        QFont font1;
        font1.setPointSize(12);
        firstnameLabel->setFont(font1);

        gridLayout_2->addWidget(firstnameLabel, 0, 0, 1, 1);

        firstnameField = new QLineEdit(CreateAccountWidget);
        firstnameField->setObjectName(QString::fromUtf8("firstnameField"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(firstnameField->sizePolicy().hasHeightForWidth());
        firstnameField->setSizePolicy(sizePolicy1);
        firstnameField->setMinimumSize(QSize(200, 0));
        firstnameField->setFont(font1);
        firstnameField->setStyleSheet(QString::fromUtf8("margin-bottom:10px;"));

        gridLayout_2->addWidget(firstnameField, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lastnameLabel = new QLabel(CreateAccountWidget);
        lastnameLabel->setObjectName(QString::fromUtf8("lastnameLabel"));
        lastnameLabel->setFont(font1);

        gridLayout_3->addWidget(lastnameLabel, 0, 0, 1, 1);

        lastnameField = new QLineEdit(CreateAccountWidget);
        lastnameField->setObjectName(QString::fromUtf8("lastnameField"));
        sizePolicy1.setHeightForWidth(lastnameField->sizePolicy().hasHeightForWidth());
        lastnameField->setSizePolicy(sizePolicy1);
        lastnameField->setMinimumSize(QSize(200, 0));
        lastnameField->setFont(font1);
        lastnameField->setStyleSheet(QString::fromUtf8("margin-bottom:10px;"));

        gridLayout_3->addWidget(lastnameField, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        usernameLabel = new QLabel(CreateAccountWidget);
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

        gridLayout_4->addWidget(usernameLabel, 0, 0, 1, 1);

        usernameField = new QLineEdit(CreateAccountWidget);
        usernameField->setObjectName(QString::fromUtf8("usernameField"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(usernameField->sizePolicy().hasHeightForWidth());
        usernameField->setSizePolicy(sizePolicy3);
        usernameField->setMinimumSize(QSize(200, 0));
        usernameField->setFont(font1);
        usernameField->setStyleSheet(QString::fromUtf8("margin-bottom:10px;"));

        gridLayout_4->addWidget(usernameField, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        passwordLabel = new QLabel(CreateAccountWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        sizePolicy2.setHeightForWidth(passwordLabel->sizePolicy().hasHeightForWidth());
        passwordLabel->setSizePolicy(sizePolicy2);
        passwordLabel->setFont(font1);
        passwordLabel->setAutoFillBackground(false);
        passwordLabel->setStyleSheet(QString::fromUtf8("background-color:none"));

        gridLayout_5->addWidget(passwordLabel, 0, 0, 1, 1);

        passwordField = new QLineEdit(CreateAccountWidget);
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        sizePolicy1.setHeightForWidth(passwordField->sizePolicy().hasHeightForWidth());
        passwordField->setSizePolicy(sizePolicy1);
        passwordField->setMinimumSize(QSize(200, 0));
        passwordField->setFont(font1);
        passwordField->setStyleSheet(QString::fromUtf8("margin-bottom:20px;"));

        gridLayout_5->addWidget(passwordField, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        createAccountButton = new QPushButton(CreateAccountWidget);
        createAccountButton->setObjectName(QString::fromUtf8("createAccountButton"));
        createAccountButton->setFont(font1);

        horizontalLayout_2->addWidget(createAccountButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        backButton = new QPushButton(CreateAccountWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);
        backButton->setMaximumSize(QSize(16777215, 16777215));
        backButton->setFont(font1);
        backButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_6->addWidget(backButton, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_6, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 2, 1, 2);


        retranslateUi(CreateAccountWidget);

        QMetaObject::connectSlotsByName(CreateAccountWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateAccountWidget)
    {
        CreateAccountWidget->setWindowTitle(QCoreApplication::translate("CreateAccountWidget", "CreateAccountWidget", nullptr));
        titleLabel->setText(QCoreApplication::translate("CreateAccountWidget", "Tic-Tac-Toe Infinity 2.0", nullptr));
        firstnameLabel->setText(QCoreApplication::translate("CreateAccountWidget", "First Name", nullptr));
        lastnameLabel->setText(QCoreApplication::translate("CreateAccountWidget", "Last Name", nullptr));
        usernameLabel->setText(QCoreApplication::translate("CreateAccountWidget", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("CreateAccountWidget", "Password", nullptr));
        createAccountButton->setText(QCoreApplication::translate("CreateAccountWidget", "Create Account", nullptr));
        backButton->setText(QCoreApplication::translate("CreateAccountWidget", "< Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAccountWidget: public Ui_CreateAccountWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNTWIDGET_H
