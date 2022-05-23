#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task2.h"
#include "HashTable.h"
#include <qmessagebox.h>

class Task2 : public QMainWindow
{
    Q_OBJECT

public:
    Task2(QWidget *parent = Q_NULLPTR);
private:
    Ui::Task2Class ui;
    HashTable* table;
    int tableItemsCount;
private slots:
    void on_addBtn_clicked();
    void on_removeBtn_clicked();
    void on_searchBtn_clicked();
    void on_getNumberBtn_clicked();
};
