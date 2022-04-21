#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Variables");
    ui->comboBox->addItem("Classes, Structs and Arrays Count");
    ui->comboBox->addItem("Function prototypes");
    ui->comboBox->addItem("Var changed coords");
    ui->comboBox->addItem("Loacal vars count");
    ui->comboBox->addItem("Override functions");
    ui->comboBox->addItem("If depth");
    ui->comboBox->addItem("Logical mistakes");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit_2->clear();
    QStringList strList;
    strList = ui->plainTextEdit->toPlainText().split("\n", QString::SkipEmptyParts);

    if (ui->comboBox->currentText() == "Variables") {
        int Count = 0;
        std::string s = "";
        for (int i = 0; i < strList.size(); i++) {
            std::string str = strList[i].toStdString();
            std::cmatch result;
            std::cmatch resultInit;

            std::regex regularForVar(
                               "(int|double|long|size_t|std::string|float|bool|char|char\\*|short|long long)"
                               "(\\s)"
                               "([\\w-]+)"
                               "(;)"
                        );
            std::regex regularForVarInit(
                               "(int|double|long|size_t|std::string|float)"
                               "(\\s)"
                               "([\\w-]+)"
                               "(\\s*=\\s*[\\w]+)"
                               "(;)"
                        );
            if (std::regex_search(str.c_str(), result, regularForVar)) {
                Count++;

                for (unsigned int i = 1; i < result.size(); i++) {
                    s += result[i];
                }
            }
            if (std::regex_search(str.c_str(), resultInit, regularForVarInit)) {
                Count++;

                for (unsigned int i = 1; i < resultInit.size(); i++) {
                    s += resultInit[i];
                }

            }
        }
        ui->plainTextEdit_2->appendPlainText("Vars: " + QString::fromStdString(s) +"\nCount: " +  QString::number(Count));
    }


    if (ui->comboBox->currentText() == "Classes, Structs and Arrays Count") {
        int classesCount = 0;
        for (int i = 0; i < strList.size(); i++) {
            std::string str = strList[i].toStdString();

            std::regex regularForClass(
                               "(Class)"
                               "(\\s)"
                               "([\\w-]+)"
                               "([\\s]*)"
                               "(\\{)"
                        );
            if (std::regex_search(str.c_str(), regularForClass)) {
                classesCount++;
            }
        }
        ui->plainTextEdit_2->appendPlainText("Classes Count: " +  QString::number(classesCount));
        int structsCount = 0;
        for (int i = 0; i < strList.size(); i++) {
            std::string str = strList[i].toStdString();

            std::regex regularForStruct(
                               "(Struct)"
                               "(\\s)"
                               "([\\w-]+)"
                               "([\\s]*)"
                               "(\\{)"
                        );
            if (std::regex_search(str.c_str(), regularForStruct)) {
                structsCount++;
            }
        }
        ui->plainTextEdit_2->appendPlainText("Structs Count: " +  QString::number(structsCount));


        int arrsCount = 0;
        for (int i = 0; i < strList.size(); i++) {
            std::string str = strList[i].toStdString();

            std::regex regularForStruct(
                               "(int|double|long|size_t|std::string|float|bool|char|char\\*|short|long long)"
                               "(\\s)"
                               "([\\w-]+)"
                               "(\\s*)"
                               "\\[\\s*\\d*\\s*\\]"
                        );
            if (std::regex_search(str.c_str(), regularForStruct)) {
                arrsCount++;
            }
        }
        ui->plainTextEdit_2->appendPlainText("Arrays Count: " +  QString::number(arrsCount));
    }


    if (ui->comboBox->currentText() == "Function prototypes") {
        std::string s = "";
        for (int i = 0; i < strList.size(); i++) {
            std::string str = strList[i].toStdString();
            std::cmatch resultPrototypeFunction;

            std::regex regularForPrototype(
                               "(int|double|long|size_t|std::string|float|bool|char|char\\*|short|long long)"
                               "(\\s)"
                               "([\\w-]+\\s*)"
                               "(\\()"
                               "([\\w*\\s*\\,*]*)"
                               "(\\))"
                        );
            if (std::regex_search(str.c_str(), resultPrototypeFunction, regularForPrototype)) {
                for (unsigned int i = 1; i < resultPrototypeFunction.size(); i++) {
                    s += resultPrototypeFunction[i];
                }
            }
            s += ";\n";

        }
        ui->plainTextEdit_2->appendPlainText("Function prototypes: " + QString::fromStdString(s));
    }


}


