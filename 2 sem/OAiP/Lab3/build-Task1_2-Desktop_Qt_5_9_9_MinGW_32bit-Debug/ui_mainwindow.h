/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QPushButton *openFileBtn;
    QPushButton *saveFileBtn;
    QLineEdit *nameLE;
    QLabel *label;
    QLineEdit *countLE;
    QLineEdit *priceLE;
    QLineEdit *dateLE;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *printListBtn;
    QPushButton *printWaitListBtn;
    QPushButton *addBtn;
    QPushButton *addWaitBtn;
    QLineEdit *searchByNameLE;
    QPushButton *searchByNameBtn;
    QLineEdit *searchByDateLE;
    QPushButton *searchByDateBtn;
    QLabel *label_5;
    QPushButton *searchByPriceBtn;
    QLineEdit *searchByPriceLE;
    QLabel *label_6;
    QPushButton *popBtn;
    QPushButton *popWaitBtn;
    QPushButton *eraseBtn;
    QPushButton *inisertBtn;
    QLineEdit *posLineEdit;
    QLabel *label_7;
    QPushButton *sortBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 777);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(450, 10, 331, 511));
        plainTextEdit->setReadOnly(true);
        openFileBtn = new QPushButton(centralwidget);
        openFileBtn->setObjectName(QStringLiteral("openFileBtn"));
        openFileBtn->setGeometry(QRect(450, 540, 161, 51));
        saveFileBtn = new QPushButton(centralwidget);
        saveFileBtn->setObjectName(QStringLiteral("saveFileBtn"));
        saveFileBtn->setGeometry(QRect(620, 540, 161, 51));
        nameLE = new QLineEdit(centralwidget);
        nameLE->setObjectName(QStringLiteral("nameLE"));
        nameLE->setGeometry(QRect(110, 20, 301, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 101, 41));
        countLE = new QLineEdit(centralwidget);
        countLE->setObjectName(QStringLiteral("countLE"));
        countLE->setGeometry(QRect(110, 70, 301, 41));
        priceLE = new QLineEdit(centralwidget);
        priceLE->setObjectName(QStringLiteral("priceLE"));
        priceLE->setGeometry(QRect(110, 120, 301, 41));
        dateLE = new QLineEdit(centralwidget);
        dateLE->setObjectName(QStringLiteral("dateLE"));
        dateLE->setGeometry(QRect(110, 170, 301, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 101, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 101, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 170, 101, 41));
        printListBtn = new QPushButton(centralwidget);
        printListBtn->setObjectName(QStringLiteral("printListBtn"));
        printListBtn->setGeometry(QRect(450, 600, 161, 51));
        printWaitListBtn = new QPushButton(centralwidget);
        printWaitListBtn->setObjectName(QStringLiteral("printWaitListBtn"));
        printWaitListBtn->setGeometry(QRect(620, 600, 161, 51));
        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(10, 230, 191, 51));
        addWaitBtn = new QPushButton(centralwidget);
        addWaitBtn->setObjectName(QStringLiteral("addWaitBtn"));
        addWaitBtn->setGeometry(QRect(220, 230, 191, 51));
        searchByNameLE = new QLineEdit(centralwidget);
        searchByNameLE->setObjectName(QStringLiteral("searchByNameLE"));
        searchByNameLE->setGeometry(QRect(10, 460, 221, 41));
        searchByNameBtn = new QPushButton(centralwidget);
        searchByNameBtn->setObjectName(QStringLiteral("searchByNameBtn"));
        searchByNameBtn->setGeometry(QRect(240, 460, 171, 41));
        searchByDateLE = new QLineEdit(centralwidget);
        searchByDateLE->setObjectName(QStringLiteral("searchByDateLE"));
        searchByDateLE->setGeometry(QRect(10, 510, 221, 41));
        searchByDateBtn = new QPushButton(centralwidget);
        searchByDateBtn->setObjectName(QStringLiteral("searchByDateBtn"));
        searchByDateBtn->setGeometry(QRect(240, 510, 171, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 560, 351, 21));
        searchByPriceBtn = new QPushButton(centralwidget);
        searchByPriceBtn->setObjectName(QStringLiteral("searchByPriceBtn"));
        searchByPriceBtn->setGeometry(QRect(240, 590, 171, 41));
        searchByPriceLE = new QLineEdit(centralwidget);
        searchByPriceLE->setObjectName(QStringLiteral("searchByPriceLE"));
        searchByPriceLE->setGeometry(QRect(10, 590, 221, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 640, 401, 21));
        popBtn = new QPushButton(centralwidget);
        popBtn->setObjectName(QStringLiteral("popBtn"));
        popBtn->setGeometry(QRect(10, 290, 191, 51));
        popWaitBtn = new QPushButton(centralwidget);
        popWaitBtn->setObjectName(QStringLiteral("popWaitBtn"));
        popWaitBtn->setGeometry(QRect(220, 290, 191, 51));
        eraseBtn = new QPushButton(centralwidget);
        eraseBtn->setObjectName(QStringLiteral("eraseBtn"));
        eraseBtn->setGeometry(QRect(220, 400, 191, 51));
        inisertBtn = new QPushButton(centralwidget);
        inisertBtn->setObjectName(QStringLiteral("inisertBtn"));
        inisertBtn->setGeometry(QRect(10, 400, 191, 51));
        posLineEdit = new QLineEdit(centralwidget);
        posLineEdit->setObjectName(QStringLiteral("posLineEdit"));
        posLineEdit->setGeometry(QRect(50, 350, 361, 41));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 350, 31, 41));
        sortBtn = new QPushButton(centralwidget);
        sortBtn->setObjectName(QStringLiteral("sortBtn"));
        sortBtn->setGeometry(QRect(10, 670, 401, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        openFileBtn->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        saveFileBtn->setText(QApplication::translate("MainWindow", "Save File", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Product name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Count:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Price:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Income date:", Q_NULLPTR));
        printListBtn->setText(QApplication::translate("MainWindow", "Print List", Q_NULLPTR));
        printWaitListBtn->setText(QApplication::translate("MainWindow", "Print Wait List", Q_NULLPTR));
        addBtn->setText(QApplication::translate("MainWindow", "Add New Product", Q_NULLPTR));
        addWaitBtn->setText(QApplication::translate("MainWindow", "Add To Wait List", Q_NULLPTR));
        searchByNameBtn->setText(QApplication::translate("MainWindow", "Search By Name", Q_NULLPTR));
        searchByDateBtn->setText(QApplication::translate("MainWindow", "Search By Date", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "display goods stored greater than the entered value", Q_NULLPTR));
        searchByPriceBtn->setText(QApplication::translate("MainWindow", "Search By Price", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "displays products whose cost is lower than the entered value", Q_NULLPTR));
        popBtn->setText(QApplication::translate("MainWindow", "Delete From LIst", Q_NULLPTR));
        popWaitBtn->setText(QApplication::translate("MainWindow", "Delete From Wait List", Q_NULLPTR));
        eraseBtn->setText(QApplication::translate("MainWindow", "Erase From LIst", Q_NULLPTR));
        inisertBtn->setText(QApplication::translate("MainWindow", "Insert New Product", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Pos:", Q_NULLPTR));
        sortBtn->setText(QApplication::translate("MainWindow", "Sort", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
