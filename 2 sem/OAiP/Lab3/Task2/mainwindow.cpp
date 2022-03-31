#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::string indexes;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::balanced(std::string s)
{
    Stack stack;
    int i = 0;
    int j = 1;
    for (char c : s) {
        i++;
        switch (c) {

        case '\n': {i = 0; j++;} break;
        case '(': {stack.push(')');indexes = "x:" + std::to_string(i)+ "and y:" + std::to_string(j);} break;
        case '[': {stack.push(']'); indexes = "x:" + std::to_string(i)+ "and y:" + std::to_string(j);} break;
        case '{': {stack.push('}');indexes = "x:" + std::to_string(i)+ "and y:" + std::to_string(j);} break;

        case ')':
        case ']':
        case '}':
            if (stack.isEmpty() || stack.getTop() != c) {
                indexes = "x:" + std::to_string(i)+ "and y:" + std::to_string(j);
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    if (stack.isEmpty()) {
        return true;
    } else {
        return false;;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString s = ui->plainTextEdit->toPlainText();
    std::string str = s.toStdString();
    if (balanced(str)) {
        QMessageBox::information(this, "OK!", "Success");
        return;
    } else {
//        QMessageBox::information(this, "Error!", "Something wrong");
        QMessageBox::information(this, "Error!", QString::fromStdString(indexes));
        return;
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    ui->plainTextEdit->clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a file with brackets"), "D:/BSUIR/2 sem/OAiP/Lab3/Task2", tr("Text File (*.txt)"));
    QFile file(fileName);
    QString line;


    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Error!", "File is Empty");
        return;
    }

    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    } else {
        QTextStream stream(&file);

        while(!stream.atEnd()) {
              line = stream.readLine();
              ui->plainTextEdit->appendPlainText(line);
        }
        file.close();
    }
}

