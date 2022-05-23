#include "Task2.h"

Task2::Task2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.keyLE->setInputMask("99999");
    ui.valueLE->setInputMask("99999");
}

void Task2::showTable() {
    ui.listWidget->clear();
	for (auto it = table.begin(); it != table.end(); ++it) {
		QString str = QString::number(it->first) + ": " + QString::number(it->second);
		ui.listWidget->addItem(str);
	}
}

void Task2::on_insertBtn_clicked() {
	if (ui.keyLE->text().isEmpty() || ui.valueLE->text().isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Enter key and value!");
		return;
	}
	
	int key = ui.keyLE->text().toInt();
	int value = ui.valueLE->text().toInt();
	if (table.contains(key)) {
		QMessageBox::warning(this, "Warning!", "This Key already exists!");
		return;
	}
	table.insert(std::make_pair(key, value));
	showTable();
}

void Task2::on_eraseBtn_clicked() {
	if (ui.keyLE->text().isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Enter key!");
		return;
	}

	if (table.isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Table is empty!");
		return;
	}

	int key = ui.keyLE->text().toInt();
	
	if (!table.contains(key)) {
		QMessageBox::warning(this, "Warning!", "This Key doesn't exist!");
		return;
	}
	table.erase(key);
	showTable();
}

void Task2::on_clearBtn_clicked() {
	if (table.isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Table is empty!");
		return;
	}
	table.clear();
	showTable();
}

void Task2::on_containsBtn_clicked() {
	if (ui.keyLE->text().isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Enter key!");
		return;
	}

	if (table.isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Table is empty!");
		return;
	}

	int key = ui.keyLE->text().toInt();
	
	if (!table.contains(key)) {
		QMessageBox::information(this, "Information!", "This Key doesn't exist!");
	} else {
		QMessageBox::information(this, "Information!", "This Key exists!");
	}
}


