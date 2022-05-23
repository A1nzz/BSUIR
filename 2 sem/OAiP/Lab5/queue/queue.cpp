#include "queue.h"

queue::queue(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.lineEdit->setInputMask("9999");
}

void queue::showQueue() {
	ui.plainTextEdit->clear();
	auto temp_q = q;
	while (!temp_q.isEmpty()) {
		ui.plainTextEdit->appendPlainText(QString::number(temp_q.pop()));
	}
}

void queue::on_pushButton_clicked() {
	if (ui.lineEdit->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a number");
		return;
	}
	QString str = ui.lineEdit->text();
	int num = str.toInt();
	q.push(num);
	showQueue();
}

void queue::on_popButton_clicked() {
	if (q.isEmpty()) {
		QMessageBox::warning(this, "Warning", "Queue is empty");
		return;
	}
	q.pop();
	showQueue();
}