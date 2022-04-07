#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->posLineEdit->setInputMask("9999");
    ui->countLE->setInputMask("99999");
    ui->dateLE->setInputMask("99.99.9999");
    ui->priceLE->setInputMask("999999999");
    ui->searchByDateLE->setInputMask("99999");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printList()
{
    ui->plainTextEdit->clear();

    for (int i = 0; i < list.getSize(); i++) {
        Product pr = list.getProduct(i);
        ui->plainTextEdit->appendPlainText("Product name: " + QString::fromStdString(pr.name));
        ui->plainTextEdit->appendPlainText("Count: " + QString::number(pr.count));
        ui->plainTextEdit->appendPlainText("Price: " + QString::number(pr.price));
        ui->plainTextEdit->appendPlainText("Income date: " + QString::fromStdString(pr.date)+ "\n");

    }
}


void MainWindow::printWaitList()
{
    ui->plainTextEdit->clear();

    for (int i = 0; i < waitList.getSize(); i++) {
        Product pr = waitList.getProduct(i);
        ui->plainTextEdit->appendPlainText("Product name: " + QString::fromStdString(pr.name));
        ui->plainTextEdit->appendPlainText("Count: " + QString::number(pr.count));
        ui->plainTextEdit->appendPlainText("Price: " + QString::number(pr.price));
        ui->plainTextEdit->appendPlainText("Income date: " + QString::fromStdString(pr.date)+ "\n");

    }
}


void MainWindow::on_printWaitListBtn_clicked()
{
    printWaitList();
}



void MainWindow::on_addBtn_clicked()
{
    std::string name = (ui->nameLE->text()).toStdString();
    for (unsigned int i = 0; i < name.length(); i++) {
        if ((name[i] < 'A' && name[i] != ' ') || (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z') {
            QMessageBox::critical(this, "Error!", "Incorrect fullname input!");
            return;
         }
    }
    int count = QString(ui->countLE->text()).toInt();
    int price = QString(ui->priceLE->text()).toInt();
    QString strDate = ui->dateLE->text();


    if (name == "\0" || (ui->countLE->text()) == "\0" || (ui->priceLE->text()) == "\0" || strDate == "\0"){
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
        Product pr;
        pr.name = name;
        pr.count = count;
        pr.price = price;
        pr.date = date;
        list.add(pr);
        printList();
    }
}

void MainWindow::on_addWaitBtn_clicked()
{
    std::string name = (ui->nameLE->text()).toStdString();
    for (unsigned int i = 0; i < name.length(); i++) {
        if ((name[i] < 'A' && name[i] != ' ') || (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z') {
            QMessageBox::critical(this, "Error!", "Incorrect fullname input!");
            return;
         }
    }
    int count = QString(ui->countLE->text()).toInt();
    int price = QString(ui->priceLE->text()).toInt();
    QString strDate = ui->dateLE->text();


    if (name == "\0" || (ui->countLE->text()) == "\0" || (ui->priceLE->text()) == "\0" || strDate == "\0"){
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
        Product pr;
        pr.name = name;
        pr.count = count;
        pr.price = price;
        pr.date = date;
        waitList.add(pr);
        printWaitList();
    }

}



void MainWindow::on_popBtn_clicked()
{
    if (list.getSize() == 0) {
        QMessageBox::critical(this, "Error!", "Nothing to delete!");
        return;
    }
    list.pop();
    printList();
}

void MainWindow::on_popWaitBtn_clicked()
{
    if (waitList.getSize() == 0) {
        QMessageBox::critical(this, "Error!", "Nothing to delete!");
        return;
    }
    waitList.pop();
    printWaitList();
}


void MainWindow::on_searchByNameBtn_clicked()
{
    std::string name = ui->searchByNameLE->text().toStdString();
    for (unsigned int i = 0; i < name.length(); i++) {
        if ((name[i] < 'A' && name[i] != ' ') || (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z') {
            QMessageBox::critical(this, "Error!", "Incorrect fullname input!");
            return;
         }
    }

    if (name == "\0"){
            QMessageBox::critical(this, "Error!", "Fill the field for search!");
            return;
    }

    ui->plainTextEdit->clear();
    bool isExist = 0;
    for (int i = 0; i< list.getSize(); i++) {
        if (list.getProduct(i).name == name){
            isExist =1;
            Product pr = list.getProduct(i);
            ui->plainTextEdit->appendPlainText("Product name: " + QString::fromStdString(pr.name));
            ui->plainTextEdit->appendPlainText("Count: " + QString::number(pr.count));
            ui->plainTextEdit->appendPlainText("Price: " + QString::number(pr.price));
            ui->plainTextEdit->appendPlainText("Income date: " + QString::fromStdString(pr.date)+ "\n");
        }
    }
    if (!isExist) {
        QMessageBox::information(this, "Error!", "There is no product with such name");
        return;
    }
}


void MainWindow::on_searchByPriceBtn_clicked()
{
    if (ui->searchByPriceLE->text() == "\0"){
        QMessageBox::critical(this, "Error!", "Fill the field for search!");
        return;
    }

    int price = ui->searchByPriceLE->text().toInt();

    ui->plainTextEdit->clear();
    bool isExist = 0;
    for (int i = 0; i< list.getSize(); i++) {
        if (list.getProduct(i).price < price){
            isExist =1;
            Product pr = list.getProduct(i);
            ui->plainTextEdit->appendPlainText("Product name: " + QString::fromStdString(pr.name));
            ui->plainTextEdit->appendPlainText("Count: " + QString::number(pr.count));
            ui->plainTextEdit->appendPlainText("Price: " + QString::number(pr.price));
            ui->plainTextEdit->appendPlainText("Income date: " + QString::fromStdString(pr.date)+ "\n");
        }
    }
    if (!isExist) {
        QMessageBox::information(this, "Error!", "There is no product with price lower than entered one");
        return;
    }
}



void MainWindow::on_printListBtn_clicked()
{
    printList();
}


void MainWindow::on_searchByDateBtn_clicked()
{
    ui->plainTextEdit->clear();

    QString curDate = "07.04.2022";

    if (ui->searchByDateLE->text() == "\0"){
            QMessageBox::critical(this, "Error!", "Fill the field for search!");
            return;
    }

    QString year = curDate;
    year.remove(0, 6);
    while (year[0] == '0')
        year.remove(0, 1);

    QString month = curDate;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = curDate;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    int daysStorage = ui->searchByDateLE->text().toInt();

    Date cdate(day.toInt(),month.toInt(),year.toInt());

    int cdateInDays = cdate.convertToDays();

    int dateForCompareInDays = cdateInDays - daysStorage;

    bool isExist = 0;
    for (int i = 0; i< list.getSize(); i++) {
        std::string productDate = list.getProduct(i).date;

        QString productDateQ = QString::fromStdString(productDate);

        QString yearPr = productDateQ;
        yearPr.remove(0, 6);
        while (yearPr[0] == '0')
        yearPr.remove(0, 1);

        QString monthPr = productDateQ;
        monthPr.remove(0, 3); monthPr.remove(2, 5);
        if (monthPr[0] == '0') monthPr.remove(0, 1);

        QString dayPr = productDateQ;
        dayPr.remove(2, 8);
        if (dayPr[0] == '0') dayPr.remove(0, 1);

        Date prDate(dayPr.toInt(), monthPr.toInt(), yearPr.toInt());
        int productDateInDays = prDate.convertToDays();

        if (productDateInDays < dateForCompareInDays){
            isExist =1;
            Product pr = list.getProduct(i);
            ui->plainTextEdit->appendPlainText("Product name: " + QString::fromStdString(pr.name));
            ui->plainTextEdit->appendPlainText("Count: " + QString::number(pr.count));
            ui->plainTextEdit->appendPlainText("Price: " + QString::number(pr.price));
            ui->plainTextEdit->appendPlainText("Income date: " + QString::fromStdString(pr.date)+ "\n");
        }
    }
    if (!isExist) {
        QMessageBox::information(this, "Error!", "There is no product with such date");
        return;
    }
}


void MainWindow::on_inisertBtn_clicked()
{
    std::string name = (ui->nameLE->text()).toStdString();
    for (unsigned int i = 0; i < name.length(); i++) {
        if ((name[i] < 'A' && name[i] != ' ') || (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z') {
            QMessageBox::critical(this, "Error!", "Incorrect fullname input!");
            return;
         }
    }
    int count = QString(ui->countLE->text()).toInt();
    int price = QString(ui->priceLE->text()).toInt();
    QString strDate = ui->dateLE->text();
    int pos = QString(ui->posLineEdit->text()).toInt();

    if (ui->posLineEdit->text() == "\0"){
            QMessageBox::critical(this, "Error!", "Fill the pos field!!");
            return;
    }

    if (name == "\0" || (ui->countLE->text()) == "\0" || (ui->priceLE->text()) == "\0" || strDate == "\0"){
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
    } else if(pos < 0 || pos > list.getSize())
    {
        QMessageBox::critical(this, "Error!", "Incorrect position!");
        return;
    }
    else {
        Product pr;
        pr.name = name;
        pr.count = count;
        pr.price = price;
        pr.date = date;
        list.insert(pos, pr);
        printList();
    }
}


void MainWindow::on_eraseBtn_clicked()
{
    int pos = QString(ui->posLineEdit->text()).toInt();

    if (ui->posLineEdit->text() == "\0"){
            QMessageBox::critical(this, "Error!", "Fill the pos field!!");
            return;
    }

    if (list.getSize() == 0) {
        QMessageBox::critical(this, "Error!", "List is clear!");
        return;
    }

    if(pos < 0 || pos > list.getSize() - 1)
        {
            QMessageBox::critical(this, "Error!", "Incorrect position!");
            return;
        }
        else {
            list.remove(pos);
            printList();
        }
}

std::istream& operator>>(std::istream& os, Product& product) {
    getline(os, product.name);
    if (os.fail()){
            product.count = -1;
    }
    os >> product.count;
    os.ignore();
    if (os.fail()){
            product.count = -1;
    }

    os >> product.price;
    os.ignore();
    getline(os, product.date);
    os.ignore();
    return os;
}


void MainWindow::on_openFileBtn_clicked()
{


    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a file with staff"), "D:/BSUIR/2 sem/OAiP/Lab3/Task1_2", tr("Text File (*.txt)"));
    if (fileName.isEmpty())
    {
        return;
    }
    //QTextStream stream(&fileName);
    std::ifstream file(fileName.toStdString());

    QFile File(fileName);
    if (!File.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), File.errorString());
        return;
    }


    list.listClear();

    for (int i = 0; !(file.eof()); i++)
    {
        Product product;
        file >> product;
        if(product.count == -1) {
            QMessageBox::critical(this, "Error!", "Incorrect File!");
            return;
        }
        list.add(product);
    }
    printList();
}

std::fstream& operator<<(std::fstream& fout, Product product)
{
    fout << product.name << "\n";
    fout << product.count << "\n";
    fout << product.price << "\n";
    fout << product.date << "\n";
    return fout;
}


void MainWindow::on_saveFileBtn_clicked()
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

            QString fileName = saveName;
            std::fstream outFile;
            outFile.open(fileName.toStdString(), std::ios::out);
            for (int i = 0; i < list.getSize(); i++)
            {
                if (i == list.getSize() - 1) {
                    outFile << (list.getProduct(i));
                } else {
                    outFile << (list.getProduct(i)) << std::endl;
                }
            }

        }
}


void MainWindow::on_sortBtn_clicked()
{
    list.quickSort();
    printList();
}

