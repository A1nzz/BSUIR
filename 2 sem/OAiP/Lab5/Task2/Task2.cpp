#include "Task2.h"

Task2::Task2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.lineEdit->setInputMask("999");
}

void Task2::dequeShow() {
	ui.listWidget->clear();
	int idx = 0;
	for (auto i = d.begin(); i < d.end(); i++) {
		ui.listWidget->addItem(QString::number(*(i.cur)));
		idx++;
	}
}

void Task2::on_pushBackBtn_clicked() {
	if (ui.lineEdit->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a number");
		return;
	}
	int numb = ui.lineEdit->text().toInt();
    d.push_back(numb);
	dequeShow();
}

void Task2::on_pushFrontBtn_clicked() {
	if (ui.lineEdit->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a number");
		return;
	}
	int numb = ui.lineEdit->text().toInt();
	d.push_front(numb);
	dequeShow();
}
void Task2::on_popBackBtn_clicked() {
	if (d.empty()) {
		QMessageBox::warning(this, "Warning", "Deque is emty!");
		return;
	}
	d.pop_back();
	dequeShow();
}
void Task2::on_popFrontBtn_clicked() {
	if (d.empty()) {
		QMessageBox::warning(this, "Warning", "Deque is emty!");
		return;
	}
	d.pop_front();
	dequeShow();
}
void Task2::on_clearBtn_clicked() {
	d.clear();
	dequeShow();
}

