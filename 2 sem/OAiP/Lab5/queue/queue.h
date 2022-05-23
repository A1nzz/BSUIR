#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_queue.h"
#include "queueRealization.h"
#include <qmessagebox.h>

class queue : public QMainWindow
{
    Q_OBJECT

public:
    queue(QWidget *parent = Q_NULLPTR);
    void showQueue();

private:
    Ui::queueClass ui;
    Queue<int> q;
	
private slots:
    void on_pushButton_clicked();
    void on_popButton_clicked();
};
