#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include "doublelist.h"
#include <QFileDialog>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printList();


private slots:
    void on_pushBackBtn_clicked();

    void on_popBackBtn_clicked();

    void on_pushFrontBtn_clicked();

    void on_popFrontBtn_clicked();

    void on_insertBtn_clicked();

    void on_eraseBtn_clicked();

    void on_OpenFile_clicked();

    void on_SaveFile_clicked();

    void on_surnameButton_clicked();

    void on_printLIstBtn_clicked();

    void on_searchDepBtn_clicked();

    void on_printByWorkingHistoryBtn_clicked();

private:
    int membersFromFile;
    QString fileName;
    DoubleList* list;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
