#include "Task1.h"

Task1::Task1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.keyForSetLE->setInputMask("99999");
	ui.keyForMapLE->setInputMask("99999");
}

void Task1::showSet() {
	ui.lisrForSet->clear();
	if (set.root == nullptr) return;
	for (auto it = set.begin(); it != set.end(); ++it) {
		ui.lisrForSet->addItem(QString::number(it->key));
	}
}

void Task1::on_insertSetBtn_clicked() {
	if (ui.keyForSetLE->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a key");
		return;
	}
	int numb = ui.keyForSetLE->text().toInt();
	if (set.root) {
		for (auto it = set.begin(); it != set.end(); ++it) {
			if (it->key == numb) {
				QMessageBox::warning(this, "Warning!", "You have already input this value!");
				return;
			}
		}
	}
	set.insert(numb);
	showSet();
}

void Task1::on_eraseSetBtn_clicked() {
	if (ui.keyForSetLE->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a key");
		return;
	}
	int numb = ui.keyForSetLE->text().toInt();
	bool isExist = false;
	if (set.root) {
		for (auto it = set.begin(); it != set.end(); ++it) {
			if (it->key == numb) {
				isExist = true;
			}
		}
	}
	if (!isExist) {
		QMessageBox::warning(this, "Warning", "There is no such key!");
		return;
	}
	set.remove(numb);
	showSet();
}

void Task1::on_searchSetBtn_clicked() {
	if (ui.keyForSetLE->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a key");
		return;
	}
	int numb = ui.keyForSetLE->text().toInt();
	bool isExist = false;
	if (set.root) {
		for (auto it = set.begin(); it != set.end(); ++it) {
			if (it->key == numb) {
				isExist = true;
			}
		}
	}
	if (!isExist) {
		QMessageBox::warning(this, "Warning", "There is no such key!");
		return;
	}
	auto i = set.search(numb);
	if (i != nullptr) QMessageBox::information(this, "Info", "You have found element whith key: " + QString::number(i->key));
}

void Task1::showMap() {
	ui.listForMap->clear();
	if (map.root == nullptr) return;
	for (auto it = map.begin(); it != map.end(); ++it) {
		ui.listForMap->addItem(QString::number(it->data.first) + ":  " + QString::fromStdString(it->data.second));
	}
}

void Task1::on_insertMapBtn_clicked() {
	if (ui.keyForMapLE->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a key");
		return;
	}

	if (ui.valueForMapLE->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a value");
		return;
	}
    const int numb = ui.keyForMapLE->text().toInt();
	std::string val = ui.valueForMapLE->text().toStdString();
	if (map.root) {
		for (auto it = map.begin(); it != map.end(); ++it) {
			if (it->data.first == numb) {
				QMessageBox::warning(this, "Warning!", "You have already input this key!");
				return;
			}
		}
	}
	map.insert(std::make_pair(numb, val));
	showMap();
}

void Task1::on_eraseMapBtn_clicked() {
	if (ui.keyForMapLE->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a key");
		return;
	}
	int numb = ui.keyForMapLE->text().toInt();
	bool isExist = false;
	if (map.root) {
		for (auto it = map.begin(); it != map.end(); ++it) {
			if (it->data.first == numb) {
				isExist = true;
			}
		}
	}
	if (!isExist) {
		QMessageBox::warning(this, "Warning", "There is no such key!");
		return;
	}
	map.remove(numb);
	showMap();
}
void Task1::on_searchMapBtn_clicked() {
	if (ui.keyForMapLE->text() == "\0") {
		QMessageBox::warning(this, "Warning", "Please enter a key");
		return;
	}
	int numb = ui.keyForMapLE->text().toInt();

	bool isExist = false;
	if (map.root) {
		for (auto it = map.begin(); it != map.end(); ++it) {
			if (it->data.first == numb) {
				isExist = true;
			}
		}
	}
	if (!isExist) {
		QMessageBox::warning(this, "Warning", "There is no such key!");
		return;
	}

	auto i = map.search(numb);
	if (i != nullptr) QMessageBox::information(this, "Info", "You have found element whith key: " + QString::number(i->data.first) + " and value: " + QString::fromStdString(i->data.second));
}
