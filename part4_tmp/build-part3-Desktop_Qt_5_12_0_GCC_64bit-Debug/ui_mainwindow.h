/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionshutdown;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QWidget *tab_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QLabel *cpu_label;
    QLabel *cpu_content_label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_9;
    QLabel *sys_version_label;
    QLabel *sys_version_content_label;
    QGridLayout *gridLayout_7;
    QLabel *host_label;
    QLabel *host_content_label;
    QGridLayout *gridLayout_8;
    QLabel *runtime_label;
    QLabel *runtime_content_label;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_6;
    QLabel *systime_label;
    QLabel *systime_content_label;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menuBar;
    QMenu *menufile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(497, 517);
        actionshutdown = new QAction(MainWindow);
        actionshutdown->setObjectName(QString::fromUtf8("actionshutdown"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 2, 0, 1, 1, Qt::AlignRight);

        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_3->addWidget(tableWidget, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        radioButton = new QRadioButton(tab_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(30, 20, 112, 23));
        radioButton_2 = new QRadioButton(tab_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 50, 112, 23));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_12 = new QGridLayout(tab_2);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        cpu_label = new QLabel(tab_2);
        cpu_label->setObjectName(QString::fromUtf8("cpu_label"));
        cpu_label->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(cpu_label, 0, 0, 1, 1);

        cpu_content_label = new QLabel(tab_2);
        cpu_content_label->setObjectName(QString::fromUtf8("cpu_content_label"));

        gridLayout_10->addWidget(cpu_content_label, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_11->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_11->addItem(verticalSpacer_3, 5, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        sys_version_label = new QLabel(tab_2);
        sys_version_label->setObjectName(QString::fromUtf8("sys_version_label"));
        sys_version_label->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(sys_version_label, 0, 0, 1, 1);

        sys_version_content_label = new QLabel(tab_2);
        sys_version_content_label->setObjectName(QString::fromUtf8("sys_version_content_label"));

        gridLayout_9->addWidget(sys_version_content_label, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_9, 6, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(1);
        host_label = new QLabel(tab_2);
        host_label->setObjectName(QString::fromUtf8("host_label"));
        host_label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(host_label, 0, 0, 1, 1);

        host_content_label = new QLabel(tab_2);
        host_content_label->setObjectName(QString::fromUtf8("host_content_label"));

        gridLayout_7->addWidget(host_content_label, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        runtime_label = new QLabel(tab_2);
        runtime_label->setObjectName(QString::fromUtf8("runtime_label"));
        runtime_label->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(runtime_label, 0, 0, 1, 1);

        runtime_content_label = new QLabel(tab_2);
        runtime_content_label->setObjectName(QString::fromUtf8("runtime_content_label"));

        gridLayout_8->addWidget(runtime_content_label, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_8, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_11->addItem(verticalSpacer_2, 3, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        systime_label = new QLabel(tab_2);
        systime_label->setObjectName(QString::fromUtf8("systime_label"));
        systime_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(systime_label, 0, 0, 1, 1);

        systime_content_label = new QLabel(tab_2);
        systime_content_label->setObjectName(QString::fromUtf8("systime_content_label"));

        gridLayout_6->addWidget(systime_content_label, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_6, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_11->addItem(verticalSpacer_4, 7, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 497, 28));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menufile->addAction(actionshutdown);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionshutdown->setText(QApplication::translate("MainWindow", "shutdown", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "process", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "CPU", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "MEM", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "performance", nullptr));
        cpu_label->setText(QApplication::translate("MainWindow", "CPU", nullptr));
        cpu_content_label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        sys_version_label->setText(QApplication::translate("MainWindow", "System Version", nullptr));
        sys_version_content_label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        host_label->setText(QApplication::translate("MainWindow", "Host", nullptr));
        host_content_label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        runtime_label->setText(QApplication::translate("MainWindow", "Run Time", nullptr));
        runtime_content_label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        systime_label->setText(QApplication::translate("MainWindow", "System Time", nullptr));
        systime_content_label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Host", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
