#pragma once

#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include "ui_Task2.h"
#include "Deque.h"

class Task2 : public QMainWindow
{
    Q_OBJECT

public:
    Task2(QWidget *parent = Q_NULLPTR);
    void dequeShow();
private:
    Ui::Task2Class ui;
    deque<int> d;

private slots:
    void on_pushBackBtn_clicked();
    void on_pushFrontBtn_clicked();
    void on_popBackBtn_clicked();
    void on_popFrontBtn_clicked();
	void on_clearBtn_clicked();
};
