#pragma once

#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include "ui_dList.h"
#include "DoubleList.h"
#include <cstdlib>
#include <ctime>

class dList : public QMainWindow
{
    Q_OBJECT

public:
    dList(QWidget *parent = Q_NULLPTR);
    void showList();
private:
    Ui::dListClass ui;
    DoubleList list;
    DoubleList* newList;
    int curpos;
    int curpos2;

private slots:
    void on_pushButton_clicked();
    void on_popButton_clicked();
    void on_insertButton_clicked();
    void on_eraseButton_clicked();
    void on_ringsButton_clicked();
    void on_downBtn_clicked();
    void on_upBtn_clicked();
    void on_downBtn_2_clicked();
    void on_upBtn_2_clicked();
};
