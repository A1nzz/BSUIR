#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "stack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int Prior ( char a );
    double doMath(char op, double op1, double op2);
    double postfixEval(std::string postfixExpr, double a, double b, double c, double d, double e);
    std::string RPN(std::string str);
    bool balanced(std::string str);
private slots:
    void on_pushButton_clicked();

    void on_polishFormBtn_clicked();

    void on_getResultBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
