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

int MainWindow::Prior(char a)
{
    switch ( a ) {
    case '*': case '/': return 3;

    case '-': case '+': return 2;

    case '(': return 1;
    }
    return 0;

}

