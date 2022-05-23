#include "Task1.h"

Task1::Task1(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	countOfKeys = 0;
	ui.keyLineEdit->setInputMask("99999999");
	ui.keyLineEdit_2->setInputMask("99999999");
	ui.keyLineEdit_3->setInputMask("99999999");

	ui.insertBtn->setEnabled(false);
	ui.deleteBtn->setEnabled(false);
	ui.getValueBtn->setEnabled(false);
	ui.changeTraverseBtn->setEnabled(false);

}

void Task1::on_createTreeBtn_clicked() {
	tree = new Tree();
	countOfKeys = 0;

	tree->root = new Node(QString(ui.tableWidget->item(0, 0)->text()).toInt());
	std::pair<int, std::string> pair;
	pair.first = QString(ui.tableWidget->item(0, 0)->text()).toInt();
	pair.second = QString(ui.tableWidget->item(0, 1)->text()).toStdString();
	treeArr.push_back(pair);
	for (int i = 1; i < 7; i++) {
		std::pair<int, std::string> pair;
		pair.first = QString(ui.tableWidget->item(i, 0)->text()).toInt();
		pair.second = QString(ui.tableWidget->item(i, 1)->text()).toStdString();
		treeArr.push_back(pair);
		tree->root = tree->root->insert(tree->root, (ui.tableWidget->item(i, 0)->text()).toInt());
	}
	ui.tableForTree->clear();
	if (ui.comboBox->currentText() == "Traverse Inorder")
	{
		TraverseInorder(tree->root);
		countOfKeys = 0;
	}
	else if (ui.comboBox->currentText() == "Traverse Preorder")
	{
		TraversePreorder(tree->root);
		countOfKeys = 0;
	} else if (ui.comboBox->currentText() == "Traverse Postorder")
	{
		TraversePostorder(tree->root);
		countOfKeys = 0;		
	}
	ui.createTreeBtn->setEnabled(false);
	ui.insertBtn->setEnabled(true);
	ui.deleteBtn->setEnabled(true);
	ui.getValueBtn->setEnabled(true);
	ui.changeTraverseBtn->setEnabled(true);

}

void Task1::on_changeTraverseBtn_clicked() {
	ui.tableForTree->clear();
	if (ui.comboBox->currentText() == "Traverse Inorder")
	{
		TraverseInorder(tree->root);
		countOfKeys = 0;
	}
	else if (ui.comboBox->currentText() == "Traverse Preorder")
	{
		TraversePreorder(tree->root);
		countOfKeys = 0;
	}
	else if (ui.comboBox->currentText() == "Traverse Postorder")
	{
		TraversePostorder(tree->root);
		countOfKeys = 0;
	}
}


void Task1::TraverseDepthFirst(Node* n) {
	std::queue<Node*> children;
	children.push(n);
	int i = 0;
	while (!children.empty()) {
		Node* node = children.front();
		children.pop();

		PrintNode(node, i);
		i++;
		if (node->left)
			children.push(node->left);
		if (node->right)
			children.push(node->right);
	}
}

void Task1::PrintNode(Node* n, int pos) {
	ui.tableForTree->setItem(pos, 0, new QTableWidgetItem(QString::number(n->key)));
}

void Task1::TraverseInorder(Node* n) {
	if (n->left)
		TraverseInorder(n->left);
	
	PrintNode(n, countOfKeys);
	countOfKeys++;
	
	if (n->right)
		TraverseInorder(n->right);
}

void Task1::TraversePreorder(Node* n) {
	PrintNode(n, countOfKeys);
	countOfKeys++;
	if (n->left)
		TraversePreorder(n->left);

	if (n->right)
		TraversePreorder(n->right);
}

void Task1::TraversePostorder(Node* n) {
	if (n->left)
		TraversePostorder(n->left);	

	if (n->right)
		TraversePostorder(n->right);
	PrintNode(n, countOfKeys);
	countOfKeys++;
}

void Task1::on_insertBtn_clicked() {
	if (treeArr.size() == 9) {
		QMessageBox::warning(this, "Warning", "You can't insert more than 9 keys");
		return;
	}

	if (ui.keyLineEdit->text() == "\0") {
		QMessageBox::warning(this, "Warning", "You must enter a key");
		return;
	}
	if (ui.valueLineEdit->text() == "\0") {
		QMessageBox::warning(this, "Warning", "You must enter a value");
		return;
	}

	for (int i = 0; i < treeArr.size(); i++) {
		if (ui.keyLineEdit->text().toInt() == treeArr[i].first) {
			QMessageBox::warning(this, "Warning", "This key is already exist!");
			return;
		}
	}

	std::pair<int, std::string> pair;
	pair.first = QString(ui.keyLineEdit->text()).toInt();
	pair.second = QString(ui.valueLineEdit->text()).toStdString();
	treeArr.push_back(pair);

	for (int i = 0; i < treeArr.size(); i++) {
		ui.tableWidget->setItem(i,0, new QTableWidgetItem(QString::number(treeArr[i].first)));
		ui.tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(treeArr[i].second)));
	}
	
	tree->root = tree->root->insert(tree->root, QString(ui.keyLineEdit->text()).toInt());
	ui.keyLineEdit->clear();
	
	ui.tableForTree->clear();
	if (ui.comboBox->currentText() == "Traverse Inorder")
	{
		TraverseInorder(tree->root);
		countOfKeys = 0;
	}
	else if (ui.comboBox->currentText() == "Traverse Preorder")
	{
		TraversePreorder(tree->root);
		countOfKeys = 0;
	}
	else if (ui.comboBox->currentText() == "Traverse Postorder")
	{
		TraversePostorder(tree->root);
		countOfKeys = 0;
	}
}

void Task1::on_deleteBtn_clicked() {
	if (treeArr.size() == 0) {
		QMessageBox::warning(this, "Warning", "Tree is Empty!");
		return;
	}
	if (ui.keyLineEdit_2->text() == "\0") {
		QMessageBox::warning(this, "Warning", "You must enter a key");
		return;
	}
	
	int key = QString(ui.keyLineEdit_2->text()).toInt();
	bool isExist = false;
	for (int i = 0; i < treeArr.size(); i++) {
		if (treeArr[i].first == key) {
			treeArr.erase(treeArr.begin() + i);
			isExist = true;
		}			
	}
	if (!isExist) {
		QMessageBox::warning(this, "Warning", "Key doesn't exist");
		return;
	}
	tree->root = tree->root->remove(tree->root, QString(ui.keyLineEdit_2->text()).toInt());
	ui.tableForTree->clear();
	ui.tableWidget->clear();
	for (int i = 0; i < treeArr.size(); i++) {
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(treeArr[i].first)));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(treeArr[i].second)));
	}
	if (ui.comboBox->currentText() == "Traverse Inorder")
	{
		TraverseInorder(tree->root);
		countOfKeys = 0;
	}
	else if (ui.comboBox->currentText() == "Traverse Preorder")
	{
		TraversePreorder(tree->root);
		countOfKeys = 0;
	}
	else if (ui.comboBox->currentText() == "Traverse Postorder")
	{
		TraversePostorder(tree->root);
		countOfKeys = 0;
	}
}
void Task1::on_getValueBtn_clicked() {
	if (treeArr.size() == 0) {
		QMessageBox::warning(this, "Warning", "Tree is Empty!");
		return;
	}

	if (ui.keyLineEdit_3->text() == "\0") {
		QMessageBox::warning(this, "Warning", "You must enter a key");
		return;
	}

	int key = QString(ui.keyLineEdit_3->text()).toInt();
	for (int i = 0; i < treeArr.size(); i++) {
		if (treeArr[i].first == key) {
			QMessageBox::information(this, "Information", "Value = " + QString::fromStdString(treeArr[i].second));
			return;
		}
	}
	QMessageBox::warning(this, "Warning", "Key doesn't exist");
}

void Task1::on_getNofSymbols_clicked() {
	if (treeArr.size() == 0) {
		QMessageBox::warning(this, "Warning", "Tree is Empty!");
		return;
	}

	if (ui.keyLineEdit_4->text() == "\0") {
		QMessageBox::warning(this, "Warning", "You must enter a key");
		return;
	}
	for (int i = 0; i < treeArr.size(); i++) {
		if (QString(ui.keyLineEdit_4->text()).toInt() == treeArr[i].first) {
			QMessageBox::information(this, "Info", "Number of symbols = " + QString::number(treeArr[i].second.length()));
			return;
		}
	}
	QMessageBox::warning(this, "Warning", "Key doesn't exist");
}




