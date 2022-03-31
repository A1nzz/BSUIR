#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextStream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->surnameLE->setInputMask("aaaaaaaaaaaaaaaaaa");
    ui->numberLineEdit->setInputMask("999");
    ui->postLineEdit->setInputMask("aaaaaaaaaaa");
    ui->dateLineEdit->setInputMask("99.99.9999");
    ui->printByWorkingHistoryLE->setInputMask("99");
    list = new DoubleList;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::printList()
{
    ui->plainTextEdit->clear();

    for (int i = 1; i <= list->GetCount(); i++) {
        Staff* listEl = list->getElement(i);
        ui->plainTextEdit->appendPlainText(QString::fromStdString(listEl->fullname));
        ui->plainTextEdit->appendPlainText(QString::number(listEl->number));
        ui->plainTextEdit->appendPlainText(QString::fromStdString(listEl->post));
        ui->plainTextEdit->appendPlainText(QString::fromStdString(listEl->date)+ "\n");

    }
}

void MainWindow::on_pushBackBtn_clicked()
{
    std::string fname = (ui->fullnameLineEdit->text()).toStdString();
    for (unsigned int i = 0; i < fname.length(); i++) {
        if ((fname[i] < 'A' && fname[i] != ' ') || (fname[i] > 'Z' && fname[i] < 'a') || fname[i] > 'z') {
            QMessageBox::critical(this, "Error!", "Incorrect fullname input!");
            return;
         }
    }
    int numb = QString(ui->numberLineEdit->text()).toInt();
    std::string post = (ui->postLineEdit->text()).toStdString();
    QString strDate = ui->dateLineEdit->text();


    if (fname == "\0" || (ui->numberLineEdit->text()) == "\0" || post == "\0" || strDate == "\0"){
            QMessageBox::critical(this, "Error!", "Fill all the fields!");
            return;
    }

    QString year = strDate;
    year.remove(0, 6);
    while (year[0] == '0')
        year.remove(0, 1);

    QString month = strDate;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = strDate;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

     std::string date = strDate.toStdString();
    if(month.toInt() > 12  || month.toInt() < 1)
    {
        QMessageBox::critical(this, "Error!", "Input format:\ndd.mm.yyyy");
        return;
    }
    else if(day.toInt() < 1 || day.toInt() > 31)
    {
        QMessageBox::critical(this, "Error!", "Input format:\ndd.mm.yyyy");
        return;
    }
    else {
        list->push_back(fname, numb, post, date);
        printList();
    }

}


void MainWindow::on_popBackBtn_clicked()
{
    if (list->GetCount() == 0) {
        QMessageBox::critical(this, "Error!", "Nothing to delete!");
        return;
    }
    list->pop_back();
    printList();
}


void MainWindow::on_pushFrontBtn_clicked()
{
    std::string fname = (ui->fullnameLineEdit->text()).toStdString();
    for (unsigned int i = 0; i < fname.length(); i++) {
        if ((fname[i] < 'A' && fname[i] != ' ') || (fname[i] > 'Z' && fname[i] < 'a') || fname[i] > 'z') {
            QMessageBox::critical(this, "Error!", "Incorrect fullname input!");
            return;
         }
    }
    int numb = QString(ui->numberLineEdit->text()).toInt();
    std::string post = (ui->postLineEdit->text()).toStdString();
    QString strDate = ui->dateLineEdit->text();


    if (fname == "\0" || (ui->numberLineEdit->text()) == "\0" || post == "\0" || strDate == "\0"){
            QMessageBox::critical(this, "Error!", "Fill all the fields!");
            return;
    }

    QString year = strDate;
    year.remove(0, 6);
    while (year[0] == '0')
        year.remove(0, 1);

    QString month = strDate;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = strDate;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

     std::string date = strDate.toStdString();
    if(month.toInt() > 12  || month.toInt() < 1)
    {
        QMessageBox::critical(this, "Error!", "Input format:\ndd.mm.yyyy");
        return;
    }
    else if(day.toInt() < 1 || day.toInt() > 31)
    {
        QMessageBox::critical(this, "Error!", "Input format:\ndd.mm.yyyy");
        return;
    }
    else {
        list->push_front(fname, numb, post, date);
        printList();
    }
}


void MainWindow::on_popFrontBtn_clicked()
{
    if (list->GetCount() == 0) {
        QMessageBox::critical(this, "Error!", "Nothing to delete!");
        return;
    }
    list->pop_front();
    printList();
}


void MainWindow::on_insertBtn_clicked()
{
    std::string fname = (ui->fullnameLineEdit->text()).toStdString();
    for (unsigned int i = 0; i < fname.length(); i++) {
        if ((fname[i] < 'A' && fname[i] != ' ') || (fname[i] > 'Z' && fname[i] < 'a') || fname[i] > 'z') {
            QMessageBox::critical(this, "Error!", "Incorrect fullname input!");
            return;
         }
    }
    int numb = QString(ui->numberLineEdit->text()).toInt();
    std::string post = (ui->postLineEdit->text()).toStdString();
    QString strDate = ui->dateLineEdit->text();
    int pos = QString(ui->posLineEdit->text()).toInt();


    if (fname == "\0" || (ui->numberLineEdit->text()) == "\0" || post == "\0" || strDate == "\0" || (ui->posLineEdit->text()) == "\0"){
            QMessageBox::critical(this, "Error!", "Fill all the fields!");
            return;
    }

    QString year = strDate;
    year.remove(0, 6);
    while (year[0] == '0')
        year.remove(0, 1);

    QString month = strDate;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = strDate;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    std::string date = strDate.toStdString();
    if(month.toInt() > 12  || month.toInt() < 1)
    {
        QMessageBox::critical(this, "Error!", "Input format:\ndd.mm.yyyy");
        return;
    }
    else if(day.toInt() < 1 || day.toInt() > 31)
    {
        QMessageBox::critical(this, "Error!", "Input format:\ndd.mm.yyyy");
        return;
    }

    if(pos < 1 || pos > list->GetCount() + 1)
    {
        QMessageBox::critical(this, "Error!", "Incorrect position!");
        return;
    }
    else {
        list->insert(pos, fname, numb, post, date);
        printList();
    }
}


void MainWindow::on_eraseBtn_clicked()
{
    int pos = QString(ui->posLineEdit->text()).toInt();
    if (list->GetCount() == 0) {
        QMessageBox::critical(this, "Error!", "Nothing to delete!");
        return;
    }
    if(pos < 1 || pos > list->GetCount())
    {
        QMessageBox::critical(this, "Error!", "Incorrect position!");
        return;
    }
    if ((ui->posLineEdit->text()) == "\0"){
            QMessageBox::critical(this, "Error!", "Fill the position field!");
            return;
    }

    list->erase(pos);
    printList();
}


std::istream& operator>>(std::istream& os, Staff& member) {
    getline(os, member.fullname);
    if (os.fail()){
            member.number = -1;
    }
    os >> member.number;
    os.ignore();
    if (os.fail()){
            member.number = -1;
    }
    getline(os, member.post);
    getline(os, member.date);
    os.ignore();
    return os;
}

void MainWindow::on_OpenFile_clicked()
{
    list->~DoubleList();

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a file with staff"), "D:/BSUIR/2 sem/OAiP/Lab3/Task1", tr("Text File (*.txt)"));
    if (fileName.isEmpty())
    {
        list = new DoubleList;
        return;
    }
    QTextStream stream(&fileName);
    std::ifstream file(fileName.toStdString());
    for (int i = 1; !(file.eof()); i++)
    {
        Staff member;
        file >> member;
        if(member.number == -1) {
            QMessageBox::critical(this, "Error!", "Incorrect File!");
            return;
        }
        list->insert(i,member.fullname, member.number, member.post, member.date);
    }
    printList();
    membersFromFile = list->GetCount();
}

std::fstream& operator<<(std::fstream& fout, Staff& member)
{
    fout << member.fullname << "\n";
    fout << member.number << "\n";
    fout << member.post << "\n";
    fout << member.date << "\n";
    return fout;
}



void MainWindow::on_SaveFile_clicked()
{
    QString saveName = QFileDialog::getSaveFileName(this, tr("Save a file with Staff"), "", tr("Text File (*.txt)"));
        if (saveName.isEmpty())
            return;
        else {
            QFile file(saveName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"), file.errorString());
                return;
            }

            fileName = saveName;
            std::fstream outFile;
            outFile.open(fileName.toStdString(), std::ios::out);
            for (int i = 1; i <= list->GetCount(); i++)
            {
                if (i == list->GetCount()) {
                    outFile << *(list->getElement(i));
                } else {
                    outFile << *(list->getElement(i)) << std::endl;
                }
            }

        }
}


void MainWindow::on_surnameButton_clicked()
{
    std::string strSurname = (ui->surnameLE->text()).toStdString();
    Staff* ElWithSurname =  list->searchElementBySurname(strSurname);
    if (ElWithSurname == nullptr) {
        QMessageBox::critical(this, "Error!", "There is no staff with such surname!");
        return;
    }
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(QString::fromStdString(ElWithSurname->fullname));
    ui->plainTextEdit->appendPlainText(QString::number(ElWithSurname->number));
    ui->plainTextEdit->appendPlainText(QString::fromStdString(ElWithSurname->post));
    ui->plainTextEdit->appendPlainText(QString::fromStdString(ElWithSurname->date)+ "\n");
}


void MainWindow::on_printLIstBtn_clicked()
{
    printList();
}


void MainWindow::on_searchDepBtn_clicked()
{
    ui->plainTextEdit->clear();
    bool isExist = false;
    int numb = QString(ui->searchDepLE->text()).toInt();
    for (int i = 1; i <= list->GetCount(); i++) {
        if (list->getElement(i)->number == numb) {
            Staff* El = list->getElement(i);
            ui->plainTextEdit->appendPlainText(QString::fromStdString(El->fullname));
            ui->plainTextEdit->appendPlainText(QString::number(El->number));
            ui->plainTextEdit->appendPlainText(QString::fromStdString(El->post));
            ui->plainTextEdit->appendPlainText(QString::fromStdString(El->date)+ "\n");
            isExist = true;
        }
    }
    if (!isExist){
        printList();
        QMessageBox::critical(this, "Error!", "There is no staff with such departament number!");
        return;
    }
}


void MainWindow::on_printByWorkingHistoryBtn_clicked()
{
    ui->plainTextEdit->clear();
    bool isExist = false;
    int workExp = QString(ui->printByWorkingHistoryLE->text()).toInt();
    int startYear = 2022 - workExp;
    for (int i = 1; i <= list->GetCount(); i++) {
        if (std::stoi(list->getElement(i)->getYear(list->getElement(i)->date)) <= startYear) {
            Staff* El = list->getElement(i);
            ui->plainTextEdit->appendPlainText(QString::fromStdString(El->fullname));
            ui->plainTextEdit->appendPlainText(QString::number(El->number));
            ui->plainTextEdit->appendPlainText(QString::fromStdString(El->post));
            ui->plainTextEdit->appendPlainText(QString::fromStdString(El->date)+ "\n");
            isExist = true;
        }
    }
    if (!isExist){
        printList();
        QMessageBox::critical(this, "Error!", "There is no staff with such departament number!");
        return;
    }
}

