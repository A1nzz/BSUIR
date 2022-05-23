#include "Task2.h"

Task2::Task2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    tableItemsCount = 10;
    table = new HashTable(tableItemsCount);
    ui.addLineEdit->setInputMask("9999999");
    ui.removeLineEdit->setInputMask("9999999");
    ui.searchLineEdit->setInputMask("9999999");
}

void Task2::on_addBtn_clicked() {
    
    int value = ui.addLineEdit->text().toInt();
    table->Insert(value);
    QString s;
    std::stack<int> temp = table->GetItem(value % 10);
    while (!temp.empty()) {
        s += QString::number(temp.top());
        s += " ";
        temp.pop();
    }
    ui.tableWidget->setItem(value % 10, 0, new QTableWidgetItem(s));
}

void Task2::on_removeBtn_clicked() {
    int value = ui.removeLineEdit->text().toInt();
    table->Remove(value);
    QString s;
    std::stack<int> temp = table->GetItem(value % 10);
    if (temp.empty()) {
        s = " ";
    }
    else {
        while (!temp.empty()) {
            s += QString::number(temp.top());
            s += " ";
            temp.pop();
        }
    }
    
    ui.tableWidget->setItem(value % 10, 0, new QTableWidgetItem(s));
}

void Task2::on_searchBtn_clicked() {
    int value = ui.searchLineEdit->text().toInt();
    if (table->Search(value) == -1) {
        QMessageBox::warning(this, "Warning!", "There is no such element in the Table!");
        return;
    }

    int searched_value = table->Search(value);
    int hash = table->CalculateHash(value);
    QMessageBox::information(this, "Info", "Element " + QString::number(searched_value) + " has hash " + QString::number(hash));
}

void Task2::on_getNumberBtn_clicked() {
    bool isNotEmpty = false;
    int totalKeyValue = 0;
    int totalCountOfKeys = 0;
    for (int i = 0; i < tableItemsCount; i++) {
        if (!table->GetItem(i).empty()) {
            isNotEmpty = true;
            std::stack<int> temp_stack = table->GetItem(i);
            while (!temp_stack.empty()) {
                totalKeyValue += temp_stack.top();
                totalCountOfKeys++;
                temp_stack.pop();
            }
        }
    }
    if (!isNotEmpty) {
        QMessageBox::warning(this, "Warning", "Table is Empty!");
        return;

    }
    int averageKeyValue = totalKeyValue / totalCountOfKeys;
    int aboveAverageValueKeysCount = 0;
    for (int i = 0; i < tableItemsCount; i++) {
        if (!table->GetItem(i).empty()) {
            std::stack<int> temp_stack = table->GetItem(i);
            while (!temp_stack.empty()) {
                if (temp_stack.top() > averageKeyValue) {
                    aboveAverageValueKeysCount++;
                }
                temp_stack.pop();              
            }
        }
    }
    QMessageBox::information(this, "Info", "Number of keys thats value above average is: " + QString::number(aboveAverageValueKeysCount));
}




