#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "doublelist.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
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
    void printWaitList();

private slots:
    void on_addBtn_clicked();

    void on_popBtn_clicked();

    void on_searchByNameBtn_clicked();

    void on_printListBtn_clicked();

    void on_searchByDateBtn_clicked();

    void on_inisertBtn_clicked();

    void on_eraseBtn_clicked();

    void on_searchByPriceBtn_clicked();

    void on_printWaitListBtn_clicked();

    void on_addWaitBtn_clicked();

    void on_popWaitBtn_clicked();

    void on_openFileBtn_clicked();

    void on_saveFileBtn_clicked();

    void on_sortBtn_clicked();

private:
    DoubleList list;
    DoubleList waitList;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
