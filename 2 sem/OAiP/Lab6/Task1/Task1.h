#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Task1.h"
#include <qmessagebox.h>
#include <vector>
#include "Tree.h"

class Task1 : public QMainWindow
{
    Q_OBJECT

public:
    Task1(QWidget *parent = Q_NULLPTR);
    void TraverseDepthFirst(Node* n);
    void PrintNode(Node* n, int pos);
    void TraverseInorder(Node* n);
    void TraversePreorder(Node* n);
    void TraversePostorder(Node* n);
private:
    Ui::Task1Class ui;
	Tree* tree;
    std::vector<std::pair<int, std::string>> treeArr;
    int countOfKeys;

private slots:
	void on_createTreeBtn_clicked();
    void on_changeTraverseBtn_clicked();
    void on_insertBtn_clicked();
	void on_deleteBtn_clicked();
    void on_getValueBtn_clicked();
    void on_getNofSymbols_clicked();
};
