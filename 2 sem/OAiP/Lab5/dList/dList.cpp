#include "dList.h"

dList::dList(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	srand(time(0));
	ui.posLineEdit->setInputMask("999");
	curpos = 1;
	curpos2 = 1;
	ui.upBtn->setEnabled(false);
	ui.upBtn_2->setEnabled(false);
	ui.downBtn->setEnabled(false);
	ui.downBtn_2->setEnabled(false);
}

void dList::showList() {
	ui.listWidget->clear();
	for (int i = 1; i <= list.GetCount(); i++) {
		ui.listWidget->addItem(QString::number(list.getElement(i)));
	}
}

void dList::on_pushButton_clicked() {
	list.push_back(1 + rand() % 99);
	showList();
}


void dList::on_popButton_clicked() {
	if (list.GetCount() == 0) {
		QMessageBox::warning(this, "Warning", "List is empty");
		return;
	}
	list.pop_back();
	showList();
}

void dList::on_insertButton_clicked() {
	if (ui.posLineEdit->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a position");
		return;
	}
	int pos = ui.posLineEdit->text().toInt();
	if ((pos > list.GetCount() && list.GetCount() != 0) || pos < 1) {
		QMessageBox::warning(this, "Warning", "Incorrect position!");
		return;
	}
	list.insert(pos, 1 + rand() % 99);
	showList();
}


void dList::on_eraseButton_clicked() {
	if (ui.posLineEdit->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a position");
		return;
	}
	int pos = ui.posLineEdit->text().toInt();
	if ((pos > list.GetCount() && list.GetCount() != 0) || pos < 1) {
		QMessageBox::warning(this, "Warning", "Incorrect position!");
		return;
	}
	if (list.GetCount() == 0) {
		QMessageBox::warning(this, "Warning", "List is empty!");
			return;
	}
	list.erase(pos);
	showList();
}

void dList::on_ringsButton_clicked() {
	if (list.GetCount() < 3) {
		QMessageBox::warning(this, "Warning", "Pls push more items(3 or more)!");
		return;
	}
	newList = list.make_circle();
	ui.listWidget_2->clear();
	if (list.GetCount() == 0) {
		QMessageBox::warning(this, "Warning", "List 1 is empty!");
		return;
	}
	if (newList != nullptr) {
		for (int i = 1; i <= newList->GetCount(); i++) {
			ui.listWidget_2->addItem(QString::number(newList->getElement(i)));
			ui.listWidget_2->item(0)->setBackground(Qt::green);
		}
	}
	else {
		QMessageBox::warning(this, "Warning", "List 2 is empty!");
		return;
	}
	//QMessageBox::information(this, "", QString::number(list.getMaxIndex()) + " " + QString::number(list.getMinIndex()));
	showList();
	ui.pushButton->setEnabled(false);
	ui.popButton->setEnabled(false);
	ui.insertButton->setEnabled(false);
	ui.eraseButton->setEnabled(false);
	ui.ringsButton->setEnabled(false);

	ui.upBtn->setEnabled(true);
	ui.upBtn_2->setEnabled(true);
	ui.downBtn->setEnabled(true);
	ui.downBtn_2->setEnabled(true);
	ui.listWidget->item(0)->setBackground(Qt::green);
}

void dList::on_downBtn_clicked() {
	if (list.GetCount() == 0) {
		QMessageBox::warning(this, "Warning", "List 1 is empty!");
		return;
	}
	if (list.GetCount() == 1) {
		return;
	}
	auto temp = list.getNode(curpos);
	ui.listWidget->item(0)->setBackground(Qt::white);
	temp = temp->next;
	curpos = list.getIndex(temp);
	ui.listWidget->item(list.getIndex(temp) - 1)->setBackground(Qt::green);
	if (list.getIndex(temp) != 1) {
		ui.listWidget->item(list.getIndex(temp) - 2)->setBackground(Qt::white);
	}
	else {
		ui.listWidget->item(list.GetCount() - 1)->setBackground(Qt::white);
	}
}

void dList::on_upBtn_clicked() {
	if (list.GetCount() == 0) {
		QMessageBox::warning(this, "Warning", "List 1 is empty!");
		return;
	}
	if (list.GetCount() == 1) {
		return;
	}
	auto temp = list.getNode(curpos);
	temp = temp->prev.lock();
	curpos = list.getIndex(temp);
	ui.listWidget->item(list.getIndex(temp) - 1)->setBackground(Qt::green);
	if (list.getIndex(temp) == list.GetCount()) {
		ui.listWidget->item(0)->setBackground(Qt::white);
	}
	else {
		ui.listWidget->item(list.getIndex(temp))->setBackground(Qt::white);
	}
}

void dList::on_downBtn_2_clicked() {
	if (newList->GetCount() == 1) {
		return;
	}
	if (newList == nullptr) {
		QMessageBox::warning(this, "Warning", "List is empty!");
		return;
	}
	auto temp = newList->getNode(curpos2);
	ui.listWidget_2->item(0)->setBackground(Qt::white);
	temp = temp->next;
	curpos2 = newList->getIndex(temp);
	ui.listWidget_2->item(newList->getIndex(temp) - 1)->setBackground(Qt::green);
	if (newList->getIndex(temp) != 1) {
		ui.listWidget_2->item(newList->getIndex(temp) - 2)->setBackground(Qt::white);
	}
	else {
		ui.listWidget_2->item(newList->GetCount() - 1)->setBackground(Qt::white);
	}
}

void dList::on_upBtn_2_clicked() {
	if (newList->GetCount() == 1) {
		return;
	}	
	if (newList == nullptr) {
		QMessageBox::warning(this, "Warning", "List is empty!");
		return;
	}
	auto temp = newList->getNode(curpos2);
	temp = temp->prev.lock();
	curpos2 = newList->getIndex(temp);
	ui.listWidget_2->item(newList->getIndex(temp) - 1)->setBackground(Qt::green);
	if (newList->getIndex(temp) == newList->GetCount()) {
		ui.listWidget_2->item(0)->setBackground(Qt::white);
	}
	else {
		ui.listWidget_2->item(newList->getIndex(temp))->setBackground(Qt::white);
	}
}

