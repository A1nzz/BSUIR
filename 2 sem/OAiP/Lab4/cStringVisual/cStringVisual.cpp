#include "cStringVisual.h"


cStringVisual::cStringVisual(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.lineEdit_3->setInputMask("99999");
}

void cStringVisual::on_pushButton_clicked() {
    if (ui.comboBox->currentText() == "strcat") {
		//From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());
		
		//
        char* str3 = my_strcat(str1, "World");

		//From char* to QString
		QString temp3 = QString(str3);
        ui.plainTextEdit->appendPlainText(temp3);
    }

    if (ui.comboBox->currentText() == "strncat") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        if (ui.lineEdit_3->text() == "\0") {
            QMessageBox::information(this, "n", "Pls enter n");
            return;
        }
		
		int n = ui.lineEdit_3->text().toInt();
        //
        char* str3 = my_strncat(str1, "World", n);

        //From char* to QString
        QString temp3 = QString(str3);
        ui.plainTextEdit->appendPlainText(temp3);
    }

    if (ui.comboBox->currentText() == "strcpy") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        //
        char* str3 = my_strcpy(str1, "World");

        //From char* to QString
        QString temp3 = QString(str3);
        ui.plainTextEdit->appendPlainText(temp3);
    }

    if (ui.comboBox->currentText() == "strncpy") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        if (ui.lineEdit_3->text() == "\0") {
            QMessageBox::information(this, "n", "Pls enter n");
            return;
        }

        int n = ui.lineEdit_3->text().toInt();
        //
        char* str3 = my_strncpy(str1, "World", n);

        //From char* to QString
        QString temp3 = QString(str3);
        ui.plainTextEdit->appendPlainText(temp3);
    }

    if (ui.comboBox->currentText() == "strcmp") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        //
        int cmp = my_strcmp(str1, "World");

        //From char* to QString
        QString temp3 = QString::number(cmp);
        ui.plainTextEdit->appendPlainText(temp3);
    }
	
    if (ui.comboBox->currentText() == "strncmp") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        //


        if (ui.lineEdit_3->text() == "\0") {
            QMessageBox::information(this, "n", "Pls enter n");
            return;
        }

        int n = ui.lineEdit_3->text().toInt();
        int cmp = my_strncmp(str1, "World", n);

        //From char* to QString
        QString temp3 = QString::number(cmp);
        ui.plainTextEdit->appendPlainText(temp3);
    }	

    if (ui.comboBox->currentText() == "strlen") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        //
        int l = my_strlen(str1);

        //From char* to QString
        QString temp3 = QString::number(l);
        ui.plainTextEdit->appendPlainText(temp3);
    }	

    if (ui.comboBox->currentText() == "strcoll") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        //
        int cmp = my_strcoll(str1, "World");

        //From char* to QString
        QString temp3 = QString::number(cmp);
        ui.plainTextEdit->appendPlainText(temp3);
    }

    if (ui.comboBox->currentText() == "strxfrm") {
        //From QString to char*
        QString temp = ui.lineEdit->text();
        char* str1 = (char*)malloc(10);
        QByteArray ba = temp.toLatin1();
        strcpy(str1, ba.data());

        //

        if (ui.lineEdit_3->text() == "\0") {
            QMessageBox::information(this, "n", "Pls enter n");
            return;
        }

        int n = ui.lineEdit_3->text().toInt();
        int cmp = my_strxfrm(str1, "World", n);

        //From char* to QString
        QString temp3 = QString(str1);
        ui.plainTextEdit->appendPlainText(temp3);
    }
}

