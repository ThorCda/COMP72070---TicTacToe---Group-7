/********************************************************************************
** Form generated from reading UI file 'GameWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *accountButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *logoutButton;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *drawsCounter;
    QLabel *lossesCounter;
    QLabel *winsLabel;
    QLabel *winsCounter;
    QLabel *drawsLabel;
    QFrame *line;
    QLabel *lossesLabel;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QLabel *titleLabel;
    QGridLayout *gameBoard;
    ClickableLabel *bottomMiddle;
    ClickableLabel *middleRight;
    ClickableLabel *middle;
    ClickableLabel *middleLeft;
    ClickableLabel *topMiddle;
    ClickableLabel *bottomLeft;
    ClickableLabel *topRight;
    ClickableLabel *bottomRight;
    ClickableLabel *topLeft;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLabel *turnLabel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *newGameButton;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QString::fromUtf8("GameWidget"));
        GameWidget->resize(1280, 720);
        gridLayout = new QGridLayout(GameWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(20, 20, 20, 20);
        accountButton = new QPushButton(GameWidget);
        accountButton->setObjectName(QString::fromUtf8("accountButton"));

        gridLayout->addWidget(accountButton, 0, 8, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 3, 1, 1);

        logoutButton = new QPushButton(GameWidget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        gridLayout->addWidget(logoutButton, 0, 9, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        drawsCounter = new QLabel(GameWidget);
        drawsCounter->setObjectName(QString::fromUtf8("drawsCounter"));
        QFont font;
        font.setPointSize(18);
        drawsCounter->setFont(font);
        drawsCounter->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(drawsCounter, 4, 1, 1, 1);

        lossesCounter = new QLabel(GameWidget);
        lossesCounter->setObjectName(QString::fromUtf8("lossesCounter"));
        lossesCounter->setFont(font);
        lossesCounter->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lossesCounter, 2, 1, 1, 1);

        winsLabel = new QLabel(GameWidget);
        winsLabel->setObjectName(QString::fromUtf8("winsLabel"));
        winsLabel->setFont(font);
        winsLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(winsLabel, 0, 0, 1, 1);

        winsCounter = new QLabel(GameWidget);
        winsCounter->setObjectName(QString::fromUtf8("winsCounter"));
        winsCounter->setFont(font);
        winsCounter->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(winsCounter, 0, 1, 1, 1);

        drawsLabel = new QLabel(GameWidget);
        drawsLabel->setObjectName(QString::fromUtf8("drawsLabel"));
        drawsLabel->setFont(font);
        drawsLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(drawsLabel, 4, 0, 1, 1);

        line = new QFrame(GameWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 0, 1, 2);

        lossesLabel = new QLabel(GameWidget);
        lossesLabel->setObjectName(QString::fromUtf8("lossesLabel"));
        lossesLabel->setFont(font);
        lossesLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lossesLabel, 2, 0, 1, 1);

        line_2 = new QFrame(GameWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 3, 0, 1, 2);


        gridLayout->addLayout(gridLayout_2, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 5, 1, 1);

        titleLabel = new QLabel(GameWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font1;
        font1.setPointSize(26);
        titleLabel->setFont(font1);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 2);

        gameBoard = new QGridLayout();
        gameBoard->setSpacing(0);
        gameBoard->setObjectName(QString::fromUtf8("gameBoard"));
        bottomMiddle = new ClickableLabel(GameWidget);
        bottomMiddle->setObjectName(QString::fromUtf8("bottomMiddle"));
        bottomMiddle->setMinimumSize(QSize(130, 130));
        bottomMiddle->setStyleSheet(QString::fromUtf8("border-left: 5px solid black; border-right: 5px solid black;"));
        bottomMiddle->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(bottomMiddle, 2, 1, 1, 1);

        middleRight = new ClickableLabel(GameWidget);
        middleRight->setObjectName(QString::fromUtf8("middleRight"));
        middleRight->setMinimumSize(QSize(130, 130));
        middleRight->setStyleSheet(QString::fromUtf8("border-top: 5px solid black; border-bottom: 5px solid black;"));
        middleRight->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(middleRight, 1, 2, 1, 1);

        middle = new ClickableLabel(GameWidget);
        middle->setObjectName(QString::fromUtf8("middle"));
        middle->setMinimumSize(QSize(130, 130));
        middle->setStyleSheet(QString::fromUtf8("border: 5px solid black;"));
        middle->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(middle, 1, 1, 1, 1);

        middleLeft = new ClickableLabel(GameWidget);
        middleLeft->setObjectName(QString::fromUtf8("middleLeft"));
        middleLeft->setMinimumSize(QSize(130, 130));
        middleLeft->setStyleSheet(QString::fromUtf8("border-top: 5px solid black; border-bottom: 5px solid black;"));
        middleLeft->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(middleLeft, 1, 0, 1, 1);

        topMiddle = new ClickableLabel(GameWidget);
        topMiddle->setObjectName(QString::fromUtf8("topMiddle"));
        topMiddle->setMinimumSize(QSize(130, 130));
        topMiddle->setStyleSheet(QString::fromUtf8("border-left: 5px solid black; border-right: 5px solid black;"));
        topMiddle->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(topMiddle, 0, 1, 1, 1);

        bottomLeft = new ClickableLabel(GameWidget);
        bottomLeft->setObjectName(QString::fromUtf8("bottomLeft"));
        bottomLeft->setMinimumSize(QSize(130, 130));
        bottomLeft->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(bottomLeft, 2, 0, 1, 1);

        topRight = new ClickableLabel(GameWidget);
        topRight->setObjectName(QString::fromUtf8("topRight"));
        topRight->setMinimumSize(QSize(130, 130));
        topRight->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(topRight, 0, 2, 1, 1);

        bottomRight = new ClickableLabel(GameWidget);
        bottomRight->setObjectName(QString::fromUtf8("bottomRight"));
        bottomRight->setMinimumSize(QSize(130, 130));
        bottomRight->setAlignment(Qt::AlignCenter);

        gameBoard->addWidget(bottomRight, 2, 2, 1, 1);

        topLeft = new ClickableLabel(GameWidget);
        topLeft->setObjectName(QString::fromUtf8("topLeft"));
        topLeft->setMinimumSize(QSize(130, 130));

        gameBoard->addWidget(topLeft, 0, 0, 1, 1);


        gridLayout->addLayout(gameBoard, 3, 5, 1, 1);

        label = new QLabel(GameWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 5, 1, 1);

        turnLabel = new QLabel(GameWidget);
        turnLabel->setObjectName(QString::fromUtf8("turnLabel"));
        turnLabel->setFont(font1);
        turnLabel->setStyleSheet(QString::fromUtf8("margin-bottom:20px;"));
        turnLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(turnLabel, 2, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 6, 1, 1);

        newGameButton = new QPushButton(GameWidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));

        gridLayout->addWidget(newGameButton, 3, 8, 1, 1);


        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "GameWidget", nullptr));
        accountButton->setText(QCoreApplication::translate("GameWidget", "Account Name", nullptr));
        logoutButton->setText(QCoreApplication::translate("GameWidget", "Logout", nullptr));
        drawsCounter->setText(QCoreApplication::translate("GameWidget", "10000", nullptr));
        lossesCounter->setText(QCoreApplication::translate("GameWidget", "69", nullptr));
        winsLabel->setText(QCoreApplication::translate("GameWidget", "Wins:", nullptr));
        winsCounter->setText(QCoreApplication::translate("GameWidget", "420", nullptr));
        drawsLabel->setText(QCoreApplication::translate("GameWidget", "Draws:", nullptr));
        lossesLabel->setText(QCoreApplication::translate("GameWidget", "Losses:", nullptr));
        titleLabel->setText(QCoreApplication::translate("GameWidget", "Tic-Tac-Toe Infinity 2.0", nullptr));
        bottomMiddle->setText(QString());
        middleRight->setText(QString());
        middle->setText(QString());
        middleLeft->setText(QString());
        topMiddle->setText(QString());
        bottomLeft->setText(QString());
        topRight->setText(QString());
        bottomRight->setText(QString());
        topLeft->setText(QString());
        label->setText(QCoreApplication::translate("GameWidget", "Stats", nullptr));
        turnLabel->setText(QCoreApplication::translate("GameWidget", "It's your turn", nullptr));
        newGameButton->setText(QCoreApplication::translate("GameWidget", "New Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
