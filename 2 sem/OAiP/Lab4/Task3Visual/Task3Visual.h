#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task3Visual.h"
#include <qmessagebox.h>
#include "..\Vector\Vector.h"

class Task3Visual : public QMainWindow
{
    Q_OBJECT

public:
    Task3Visual(QWidget *parent = Q_NULLPTR);

private:
    Ui::Task3VisualClass ui;

    Vector<char> powstr(Vector<char>& str, int k);
    int len(Vector<char>& a);
    bool k_bit(Vector<char> str1, int k);
private slots:
    void on_pushButton_clicked();

};
