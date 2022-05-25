#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task3.h"
#include "BitSet.h"
#include "qmessagebox.h"

class Task3 : public QMainWindow
{
    Q_OBJECT

public:
    Task3(QWidget *parent = Q_NULLPTR);
    BitSet<50> bs;
private slots:
    void on_CreateBitSetBtn_clicked();
    void on_allBtn_clicked();
    void on_noneBtn_clicked();
    void on_anyBtn_clicked();
    void on_resetBtn_clicked();
    void on_countBtn_clicked();
    void on_sizeBtn_clicked();
    void on_setBtn_clicked();
    void on_flipBtn_clicked();
    void on_testBtn_clicked();
private:
    Ui::Task3Class ui;
};
