#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_parser.h"
#include "MyString.h"
#include <regex>

#include "Stack.h"

class Parser : public QMainWindow
{
    Q_OBJECT

public:
    Parser(QWidget *parent = Q_NULLPTR);
private:
    Ui::ParserClass ui;
    MyString test;
private slots:
    void on_pushButton_clicked();
    void on_OpenFile_clicked();
};
