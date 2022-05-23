#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task2.h"
#include "qmessagebox.h"
#include "Unordered_map.h"

class Task2 : public QMainWindow
{
    Q_OBJECT

public:
    Task2(QWidget *parent = Q_NULLPTR);
    void showTable();
private:
    Ui::Task2Class ui;
	Unordered_map<int, int> table;
private slots:
    void on_insertBtn_clicked();
    void on_eraseBtn_clicked();
    void on_clearBtn_clicked();
    void on_containsBtn_clicked();
};

