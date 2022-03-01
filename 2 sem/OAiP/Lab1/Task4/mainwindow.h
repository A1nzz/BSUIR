#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "deputy.h"

#include <QFileDialog>
#include <QMainWindow>

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
    Deputy *onePartyArr(Deputy *arr, int size);
private:

    Deputy* deputies;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
