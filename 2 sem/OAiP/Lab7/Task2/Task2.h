#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task2.h"

class Task2 : public QMainWindow
{
    Q_OBJECT

public:
    Task2(QWidget *parent = Q_NULLPTR);

private:
    Ui::Task2Class ui;
};
