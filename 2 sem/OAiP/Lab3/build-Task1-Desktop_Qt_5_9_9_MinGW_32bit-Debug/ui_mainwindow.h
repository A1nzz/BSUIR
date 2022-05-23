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
    QPushButton *OpenFile;
    QPushButton *SaveFile;
    QLineEdit *fullnameLineEdit;
    QLineEdit *numberLineEdit;
    QLineEdit *postLineEdit;
    QLineEdit *dateLineEdit;
    QPushButton *pushBackBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushFrontBtn;
    QPushButton *popBackBtn;
    QPushButton *popFrontBtn;
    QLineEdit *posLineEdit;
    QLabel *label_5;
    QPushButton *insertBtn;
    QPushButton *eraseBtn;
    QPushButton *surnameButton;
    QLineEdit *surnameLE;
    QPushButton *printLIstBtn;
    QPushButton *searchDepBtn;
    QLineEdit *searchDepLE;
    QLineEdit *printByWorkingHistoryLE;
    QPushButton *printByWorkingHistoryBtn;
    QPushButton *sortBrn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(812, 789);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(500, 10, 291, 531));
        plainTextEdit->setReadOnly(true);
        OpenFile = new QPushButton(centralwidget);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        OpenFile->setGeometry(QRect(500, 560, 141, 51));
        SaveFile = new QPushButton(centralwidget);
        SaveFile->setObjectName(QStringLiteral("SaveFile"));
        SaveFile->setGeometry(QRect(650, 560, 141, 51));
        fullnameLineEdit = new QLineEdit(centralwidget);
        fullnameLineEdit->setObjectName(QStringLiteral("fullnameLineEdit"));
        fullnameLineEdit->setGeometry(QRect(180, 20, 191, 41));
        numberLineEdit = new QLineEdit(centralwidget);
        numberLineEdit->setObjectName(QStringLiteral("numberLineEdit"));
        numberLineEdit->setGeometry(QRect(180, 80, 191, 41));
        postLineEdit = new QLineEdit(centralwidget);
        postLineEdit->setObjectName(QStringLiteral("postLineEdit"));
        postLineEdit->setGeometry(QRect(180, 140, 191, 41));
        dateLineEdit = new QLineEdit(centralwidget);
        dateLineEdit->setObjectName(QStringLiteral("dateLineEdit"));
        dateLineEdit->setGeometry(QRect(180, 200, 191, 41));
        pushBackBtn = new QPushButton(centralwidget);
        pushBackBtn->setObjectName(QStringLiteral("pushBackBtn"));
        pushBackBtn->setGeometry(QRect(180, 320, 191, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 81, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 151, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 81, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 200, 81, 41));
        pushFrontBtn = new QPushButton(centralwidget);
        pushFrontBtn->setObjectName(QStringLiteral("pushFrontBtn"));
        pushFrontBtn->setGeometry(QRect(180, 380, 191, 51));
        popBackBtn = new QPushButton(centralwidget);
        popBackBtn->setObjectName(QStringLiteral("popBackBtn"));
        popBackBtn->setGeometry(QRect(10, 320, 151, 51));
        popFrontBtn = new QPushButton(centralwidget);
        popFrontBtn->setObjectName(QStringLiteral("popFrontBtn"));
        popFrontBtn->setGeometry(QRect(10, 380, 151, 51));
        posLineEdit = new QLineEdit(centralwidget);
        posLineEdit->setObjectName(QStringLiteral("posLineEdit"));
        posLineEdit->setGeometry(QRect(180, 260, 191, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 260, 81, 41));
        insertBtn = new QPushButton(centralwidget);
        insertBtn->setObjectName(QStringLiteral("insertBtn"));
        insertBtn->setGeometry(QRect(180, 440, 191, 51));
        eraseBtn = new QPushButton(centralwidget);
        eraseBtn->setObjectName(QStringLiteral("eraseBtn"));
        eraseBtn->setGeometry(QRect(10, 440, 151, 51));
        surnameButton = new QPushButton(centralwidget);
        surnameButton->setObjectName(QStringLiteral("surnameButton"));
        surnameButton->setGeometry(QRect(180, 500, 191, 51));
        surnameLE = new QLineEdit(centralwidget);
        surnameLE->setObjectName(QStringLiteral("surnameLE"));
        surnameLE->setGeometry(QRect(10, 500, 151, 51));
        printLIstBtn = new QPushButton(centralwidget);
        printLIstBtn->setObjectName(QStringLiteral("printLIstBtn"));
        printLIstBtn->setGeometry(QRect(500, 620, 291, 50));
        searchDepBtn = new QPushButton(centralwidget);
        searchDepBtn->setObjectName(QStringLiteral("searchDepBtn"));
        searchDepBtn->setGeometry(QRect(180, 560, 191, 51));
        searchDepLE = new QLineEdit(centralwidget);
        searchDepLE->setObjectName(QStringLiteral("searchDepLE"));
        searchDepLE->setGeometry(QRect(10, 560, 151, 51));
        printByWorkingHistoryLE = new QLineEdit(centralwidget);
        printByWorkingHistoryLE->setObjectName(QStringLiteral("printByWorkingHistoryLE"));
        printByWorkingHistoryLE->setGeometry(QRect(10, 620, 151, 51));
        printByWorkingHistoryBtn = new QPushButton(centralwidget);
        printByWorkingHistoryBtn->setObjectName(QStringLiteral("printByWorkingHistoryBtn"));
        printByWorkingHistoryBtn->setGeometry(QRect(180, 620, 191, 51));
        sortBrn = new QPushButton(centralwidget);
        sortBrn->setObjectName(QStringLiteral("sortBrn"));
        sortBrn->setGeometry(QRect(10, 680, 361, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 812, 25));
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
        OpenFile->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        SaveFile->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        pushBackBtn->setText(QApplication::translate("MainWindow", "Push Back", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Fullname:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Departament Number:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Post:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Start Date:", Q_NULLPTR));
        pushFrontBtn->setText(QApplication::translate("MainWindow", "Push Front", Q_NULLPTR));
        popBackBtn->setText(QApplication::translate("MainWindow", "Pop Back", Q_NULLPTR));
        popFrontBtn->setText(QApplication::translate("MainWindow", "Pop Front", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Pos:", Q_NULLPTR));
        insertBtn->setText(QApplication::translate("MainWindow", "Insert", Q_NULLPTR));
        eraseBtn->setText(QApplication::translate("MainWindow", "Erase", Q_NULLPTR));
        surnameButton->setText(QApplication::translate("MainWindow", "Serach by surname", Q_NULLPTR));
        printLIstBtn->setText(QApplication::translate("MainWindow", "Print List", Q_NULLPTR));
        searchDepBtn->setText(QApplication::translate("MainWindow", "Print by Departament", Q_NULLPTR));
        printByWorkingHistoryBtn->setText(QApplication::translate("MainWindow", "Print by Working Experience", Q_NULLPTR));
        sortBrn->setText(QApplication::translate("MainWindow", "Sort", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
