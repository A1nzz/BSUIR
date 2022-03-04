#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    depSize = 0;
    //partyArr = new QString[1];
    deputies = new Deputy[depSize];
    ui->LEdistrcict->setInputMask("000");
    ui->LEfullName->setInputMask("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    ui->LEparty->setInputMask("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    ui->LEage->setInputMask("000");
    ui->LEprofession->setInputMask("aaaaaaaaaaaaaaaaaaaaaa");
    ui->LEincome->setInputMask("0000000000000");
    ui->LEforSearch->setInputMask("aaaaaaaaaaaaaaaaaaaaaaaaa");
}

MainWindow::~MainWindow()
{
    delete[] deputies;
    delete ui;
}


std::istream& operator>>(std::istream& os, Deputy& dep) {

    os >> dep.m_districtNumber;
    if (os.fail()){
        dep.m_districtNumber = -1;
    }
    os.ignore();
    getline(os, dep.m_fullName);
    getline(os, dep.m_party);
    os >> dep.m_age;
    os.ignore();
    getline(os, dep.m_profession);
    os >> dep.m_incomeYear;
    os.ignore();




    return os;
}

std::fstream& operator<<(std::fstream& fout, Deputy& dep)
{
    fout << "District: " << dep.m_districtNumber << "\n";
    fout << "Full name: " << dep.m_fullName << "\n";
    fout << "Party: " << dep.m_party << "\n";
    fout << "Age: " << dep.m_age << "\n";
    fout << "Profession: " << dep.m_profession << "\n";
    fout << "Income ini a last year: " << dep.m_incomeYear << "\n";
    return fout;
}

void MainWindow::outOnMomo(std::string *partyArr, Deputy *deputies, int depSize) {
    ui->plainTextEdit->clear();

    int partyNumber;
    partyArr = getPartyArr(deputies, depSize, partyNumber);
    for (int i = 0; i < partyNumber; i++) {
        ui->plainTextEdit->appendPlainText("\n" + QString(QString::fromStdString(partyArr[i]))+":");
        int reqNumber = 0;
        int averageAge = 0;
        int averageIncome = 0;
        int k = 0;
        std::string* professions = new std::string[0];
        for (int j = 0; j < depSize; j++) {
            if (deputies[j].m_party == partyArr[i]) {
                professions = AddStringArrElements(professions, k);
                professions[k] = deputies[j].m_profession;
                k++;
                reqNumber++;
                averageAge += deputies[j].m_age;
                averageIncome += deputies[j].m_incomeYear;
            }
        }
        int maxCount = 0;
        std::string maxOftenProfession;
        for (int j = 0; j < k; j++) {
            int count = 0;
            for(int l = j; l < k; l++) {
                if (professions[j] == professions[l]) {
                    count++;
                }
            }
            if (maxCount < count) {
                maxCount = count;
                maxOftenProfession = professions[j];
            }
        }

        averageAge /= reqNumber;
        averageIncome /= reqNumber;
        ui->plainTextEdit->appendPlainText("Number of requests: " + QString::number(reqNumber));
        ui->plainTextEdit->appendPlainText("Average age: " + QString::number(averageAge));
        ui->plainTextEdit->appendPlainText("Most often profession: " + QString::fromStdString(maxOftenProfession));
        ui->plainTextEdit->appendPlainText("Average income: " + QString::number(averageIncome));
    }
}

Deputy *MainWindow::AddArrElements(Deputy *arr, int size)
{
    if (size== 0)
        {
            arr = new Deputy[size + 1];
        }
        else
        {
            Deputy* arrTmp = new Deputy[size + 1];

            for (int i = 0; i < size; i++)
            {
                arrTmp[i] = arr[i];
            }
            delete[] arr;
            arr = arrTmp;
        }
    return arr;
}

std::string *MainWindow::AddStringArrElements(std::string *arr, int size)
{
    if (size== 0)
        {
            arr = new std::string[size + 1];
        }
        else
        {
            std::string* arrTmp = new std::string[size + 1];

            for (int i = 0; i < size; i++)
            {
                arrTmp[i] = arr[i];
            }
            delete[] arr;
            arr = arrTmp;
        }
    return arr;
}

std::string* MainWindow::getPartyArr(Deputy *arr, int size, int& partyNumber)
{
    partyNumber = 1;
    std::string* partyArr = new std::string[1];
    partyArr[0] = arr[0].m_party;
    for (int i = 0;i < size ;i++ ) {
        bool isFind = false;
        for (int j = 0; j < partyNumber; j++) {
            if (arr[i].m_party == partyArr[j]) {
                isFind = true;
            }
        }
        if (!isFind) {
            partyArr = AddStringArrElements(partyArr, partyNumber);
            partyNumber++;
            partyArr[partyNumber - 1] = arr[i].m_party;
        }
    }
    return partyArr;
}


void MainWindow::on_AddItemBtn_clicked()
{

    if ((ui->LEfullName->text()) == "\0" || (ui->LEdistrcict->text()) == "\0" || (ui->LEparty->text()) == "\0"
          || (ui->LEage->text()) == "\0" || (ui->LEprofession->text()) == "\0" || (ui->LEincome->text()) == "\0") {
        QMessageBox::critical(this, "Error!", "Fill in all the fields");
        return;
    }
    Deputy newDeputy;
    newDeputy.m_fullName = (ui->LEfullName->text()).toStdString();
    newDeputy.m_districtNumber = (ui->LEdistrcict->text()).toInt();
    newDeputy.m_party = (ui->LEparty->text()).toStdString();
    newDeputy.m_age = (ui->LEage->text()).toInt();
    newDeputy.m_profession = (ui->LEprofession->text()).toStdString();
    newDeputy.m_incomeYear = (ui->LEincome->text()).toInt();
    deputies = AddArrElements(deputies, depSize);
    deputies[depSize] = newDeputy;
    depSize++;
    outOnMomo(partyArr,deputies,depSize);

}


void MainWindow::on_searchBtn_clicked()
{
    if ((ui->LEforSearch->text()) == "\0") {
        QMessageBox::critical(this, "Error!", "Fill something in the field");
        return;
    }
    std::string partyForSearch = (ui->LEforSearch->text()).toStdString();
    bool isExist = false;

    for (int j = 0; j < depSize; j++) {
        if (deputies[j].m_party == partyForSearch) {
            isExist = true;
        }
    }
    if (!isExist) {
        QMessageBox::critical(this, "Error!", "There is no such parties");
        return;
    }
    ui->plainTextEdit->clear();
    for (int j = 0; j < depSize; j++) {
        if (deputies[j].m_party == partyForSearch) {
            ui->plainTextEdit->appendPlainText("\n" + QString(QString::fromStdString(partyForSearch))+":");
            ui->plainTextEdit->appendPlainText("District: " + QString::number(deputies[j].m_districtNumber));
            ui->plainTextEdit->appendPlainText("Full name: " + QString::fromStdString(deputies[j].m_fullName));
            ui->plainTextEdit->appendPlainText("Age: " + QString::number(deputies[j].m_age));
            ui->plainTextEdit->appendPlainText("Profession: " + QString::fromStdString(deputies[j].m_profession));
            ui->plainTextEdit->appendPlainText("Income in a last year: " + QString::number(deputies[j].m_incomeYear));
        }
    }   
}


void MainWindow::on_openFile_clicked()
{
    depSize = 0;
    delete[] deputies;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a file with candidates"), "D:/OAiP 2sem/Task4", tr("Text File (*.txt)"));
    if (fileName.isEmpty())
    {
        depSize = 1;
        deputies = new Deputy[1];
        return;
    }
    std::ifstream file(fileName.toStdString());
    for (depSize = 0; !(file.eof()); depSize++)
    {

        deputies = AddArrElements(deputies, depSize);
        file >> deputies[depSize];
        QFile file(fileName);
        if (deputies[depSize].m_districtNumber == -1) {
            QMessageBox::critical(this, "Error!", "Incorrect File");
            return;
        }
    }
    outOnMomo(partyArr,deputies,depSize);
    depFromFileSize = depSize;
}



void MainWindow::on_saveBtn_clicked()
{
    QString saveName = QFileDialog::getSaveFileName(this, tr("Save a file with dates"), "", tr("Text File (*.txt)"));
    if (saveName.isEmpty())
        return;
    else {
        QFile file(saveName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        if (fileName != saveName)
        {
            fileName = saveName;
            std::fstream outFile;
            outFile.open(fileName.toStdString(), std::ios::out);
            for (int i = 0; i < depSize; i++)
            {
                outFile << deputies[i] << std::endl;
            }
        } else {
            std::fstream outFile(saveName.toStdString(), std::ios::out|std::ios::app);
            for (int i = depFromFileSize; i < depSize; i++)
            {
                outFile << std::endl;
                outFile << deputies[i];
            }
        }

    }
}

