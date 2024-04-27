/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *Buttons;
    QSpacerItem *horizontalSpacer;
    QLabel *Win_table;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *SecondLeftButton;
    QPushButton *SecondRightButton;
    QPushButton *QuitButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *FirstLeftButton;
    QPushButton *FirstRightButton;
    QPushButton *PlayButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 645);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(20000, 20000));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resourses/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(53, 53, 53)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("color:white;"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Buttons = new QGridLayout();
        Buttons->setSpacing(2);
        Buttons->setObjectName(QString::fromUtf8("Buttons"));

        gridLayout_3->addLayout(Buttons, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 1, 1, 1);

        Win_table = new QLabel(centralwidget);
        Win_table->setObjectName(QString::fromUtf8("Win_table"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setKerning(false);
        Win_table->setFont(font);
        Win_table->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        Win_table->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(Win_table, 1, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resourses/o.png")));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        SecondLeftButton = new QPushButton(centralwidget);
        SecondLeftButton->setObjectName(QString::fromUtf8("SecondLeftButton"));
        SecondLeftButton->setMinimumSize(QSize(79, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        SecondLeftButton->setFont(font1);

        horizontalLayout_4->addWidget(SecondLeftButton);

        SecondRightButton = new QPushButton(centralwidget);
        SecondRightButton->setObjectName(QString::fromUtf8("SecondRightButton"));
        SecondRightButton->setMinimumSize(QSize(79, 45));
        SecondRightButton->setFont(font1);

        horizontalLayout_4->addWidget(SecondRightButton);


        verticalLayout_3->addLayout(horizontalLayout_4);

        QuitButton = new QPushButton(centralwidget);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        QuitButton->setFont(font1);
        QuitButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(241, 133, 7); border-radius: 10px;}\n"
"QPushButton:hover{background-color:rgb(221, 113, 0);}"));

        verticalLayout_3->addWidget(QuitButton);


        gridLayout_3->addLayout(verticalLayout_3, 2, 4, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(22);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resourses/ex.png")));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        FirstLeftButton = new QPushButton(centralwidget);
        FirstLeftButton->setObjectName(QString::fromUtf8("FirstLeftButton"));
        FirstLeftButton->setMinimumSize(QSize(79, 45));
        FirstLeftButton->setFont(font1);

        horizontalLayout_3->addWidget(FirstLeftButton);

        FirstRightButton = new QPushButton(centralwidget);
        FirstRightButton->setObjectName(QString::fromUtf8("FirstRightButton"));
        FirstRightButton->setMinimumSize(QSize(79, 45));
        FirstRightButton->setFont(font1);

        horizontalLayout_3->addWidget(FirstRightButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        PlayButton = new QPushButton(centralwidget);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        PlayButton->setFont(font1);
        PlayButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(38, 144, 219); border-radius: 10px;}\n"
"QPushButton:hover{background-color:rgb(18, 124, 199);}"));

        verticalLayout_2->addWidget(PlayButton);


        gridLayout_3->addLayout(verticalLayout_2, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer, 4, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menubar->setStyleSheet(QString::fromUtf8("QMenuBar{background-color:#4a5459; color:white;}"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TicTacToe", nullptr));
        Win_table->setText(QCoreApplication::translate("MainWindow", "TicTacToe", nullptr));
        label_3->setText(QString());
        SecondLeftButton->setText(QCoreApplication::translate("MainWindow", "You", nullptr));
        SecondRightButton->setText(QCoreApplication::translate("MainWindow", "Comp.", nullptr));
        QuitButton->setText(QCoreApplication::translate("MainWindow", "Give up", nullptr));
        label_2->setText(QString());
        FirstLeftButton->setText(QCoreApplication::translate("MainWindow", "You", nullptr));
        FirstRightButton->setText(QCoreApplication::translate("MainWindow", "Comp.", nullptr));
        PlayButton->setText(QCoreApplication::translate("MainWindow", "Play!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
