#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task1.h"
#include "Set.h"
#include "Map.h"
#include <qmessagebox.h>

class Task1 : public QMainWindow
{
    Q_OBJECT

public:
    Task1(QWidget *parent = Q_NULLPTR);
    void showSet();
    void showMap();
private:
    Ui::Task1Class ui;
    Set<int> set;
    Map<int, std::string> map;
private slots:
    void on_insertSetBtn_clicked();
    void on_eraseSetBtn_clicked();
    void on_searchSetBtn_clicked();
    void on_insertMapBtn_clicked();
    void on_eraseMapBtn_clicked();
    void on_searchMapBtn_clicked();
};
