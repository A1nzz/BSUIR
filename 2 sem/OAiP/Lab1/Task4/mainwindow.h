#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "deputy.h"

#include <QFileDialog>
#include <QMainWindow>
#include <QString>
#include <QFile>
#include <fstream>
#include <string>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Deputy *AddArrElements(Deputy *arr, int size);
    std::string *AddStringArrElements(std::string *arr, int size);
    std::string* getPartyArr(Deputy *arr, int size, int& partyNumber);

    void outOnMomo(std::string *partyArr, Deputy *deputies, int depSize) ;


private slots:
    void on_openFile_clicked();

    void on_AddItemBtn_clicked();

    void on_searchBtn_clicked();

    void on_saveBtn_clicked();

private:
    int depSize;
    int depFromFileSize;
    QString fileName;
    Deputy* deputies;
    std::string *partyArr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
