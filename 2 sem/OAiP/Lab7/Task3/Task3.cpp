#include "Task3.h"

Task3::Task3(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.bitsetValue->setInputMask("999999");
    ui.posLE->setInputMask("999999");
    ui.resultLE->setText(QString::fromStdString(bs.to_string()));

}

void Task3::on_CreateBitSetBtn_clicked() {
    int numb = ui.bitsetValue->text().toInt();
    bs = numb;
    ui.resultLE->setText(QString::fromStdString(bs.to_string()));
}

void Task3::on_allBtn_clicked() {
    QMessageBox::information(this, "Info", "Method All result: " + QString::number(bs.all()));
}
void Task3::on_noneBtn_clicked() {
    QMessageBox::information(this, "Info", "Method None result: " + QString::number(bs.none()));
}

void Task3::on_anyBtn_clicked() {
    QMessageBox::information(this, "Info", "Method Any result: " + QString::number(bs.any()));
}

void Task3::on_countBtn_clicked() {
    QMessageBox::information(this, "Info", "Method Count result: " + QString::number(bs.count()));
}
void Task3::on_sizeBtn_clicked() {
    QMessageBox::information(this, "Info", "Method Size result: " + QString::number(bs.Size()));
}

void Task3::on_testBtn_clicked() {
    if (ui.posLE->text().isEmpty()) {
        QMessageBox::information(this, "Info", "Enter position to test!");
    }
	
    else if (ui.posLE->text().toInt() >= bs.Size()) {
        QMessageBox::information(this, "Info", "Incorrect position!(pos >= size)");
    }
    else {
        QMessageBox::information(this, "Info", "Method Size result: " + QString::number(bs.test(ui.posLE->text().toInt())));
    }
}


void Task3::on_resetBtn_clicked() {
    if (ui.posLE->text().isEmpty()) {
        bs.reset();
    }
    else if (ui.posLE->text().toInt() >= bs.Size()) {
        QMessageBox::information(this, "Info", "Incorrect position!(pos >= size)");
    }
    else {
        bs.reset(ui.posLE->text().toInt());
    }
    ui.resultLE->setText(QString::fromStdString(bs.to_string()));
}

void Task3::on_setBtn_clicked() {
    if (ui.posLE->text().isEmpty()) {
        bs.set();
    }
    else if (ui.posLE->text().toInt() >= bs.Size()) {
        QMessageBox::information(this, "Info", "Incorrect position!(pos >= size)");
    }	
    else {
        bs.set(ui.posLE->text().toInt());
    }
    ui.resultLE->setText(QString::fromStdString(bs.to_string()));
}
void Task3::on_flipBtn_clicked() {
    if (ui.posLE->text().isEmpty()) {
        bs.flip();
    }
    else if (ui.posLE->text().toInt() >= bs.Size()) {
        QMessageBox::information(this, "Info", "Incorrect position!(pos >= size)");
    }
    else {
        bs.flip(ui.posLE->text().toInt());
    }
    ui.resultLE->setText(QString::fromStdString(bs.to_string()));
}