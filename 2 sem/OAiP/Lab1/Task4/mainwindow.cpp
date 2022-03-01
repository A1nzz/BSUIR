#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Deputy *MainWindow::AddArrElements(Deputy *arr, int size)
{
    if (size== 0)
        {
            arr = new Deputy[size + 1];
        }
        else
        {
            Deputy* arrTmp = new Deputy[size + 1];

            for (int i = 0; i < size; i++)
            {
                arrTmp[i] = arr[i];
            }
            delete[] arr;
            arr = arrTmp;
        }
    return arr;
}

Deputy *MainWindow::onePartyArr(Deputy *arr, int size)
{

}

