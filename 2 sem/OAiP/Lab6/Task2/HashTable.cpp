#include "HashTable.h"


HashTable::HashTable(int size) {
	this->size = size;
	this->items = new std::stack<int>[size];
	this->count = 0;
}

HashTable::~HashTable() {
	delete[] this->items;
}

void HashTable::Insert(int value) {
	int index = this->CalculateHash(value);
	std::stack<int> values = this->items[index];

	std::stack<int> temp_values = values;
	while (!temp_values.empty()) {
		if (temp_values.top() == value) {
			return;
		} 
		temp_values.pop();
	}
	
	values.push(value);
	items[index] = values;
	//if (values.top() % size == index) { // check for collusion
	//	values.push(value);
	//	items[index] = values;
	//}
	//else {
	//	values.push(value);
	//	items[index] = values;
	//}
	count++;
}

int HashTable::Search(int value) {
	int index = this->CalculateHash(value);
	std::stack<int> values = this->items[index];
	std::stack<int> temp_values = values;
	while (!temp_values.empty()) {
		if (temp_values.top() == value) {
			return temp_values.top();
		}
		else {
			temp_values.pop();
		}
	}
	this->items[index] = values;
	return -1;
}

void HashTable::Remove(int value) {
	int index = this->CalculateHash(value);
	std::stack<int> values = this->items[index];
	std::stack<int> temp_values = values;
	bool isExist = false;

	while (!temp_values.empty()) {
		if (temp_values.top() == value) {
			isExist = true;
			break;
		}
		else {
			temp_values.pop();
		}
	}
	if (isExist) {
		temp_values = values;
		std::stack<int> temp_stack;
		while (temp_values.top() != value) {
			temp_stack.push(temp_values.top());
			temp_values.pop();
		} 
		temp_values.pop();
		while (!temp_stack.empty()) {
			temp_values.push(temp_stack.top());
			temp_stack.pop();
		}
		values = temp_values;
		items[index] = values;
		count--;
	}
	/*std::stack<int> temp_values = values;
	bool isExist = false;
	while (!temp_values.empty()) {
		if (temp_values.top() == value) {
			isExist = true;
		}
		else {
			temp_values.pop();
		}
	}
	if (isExist) {
		std::stack<int> stack;
		while (values.top() != value) {
			stack.push(values.top());
			values.pop();
		}
		while (!stack.empty()) {
			temp_values.push(stack.top());
			stack.pop();
		}
		values = temp_values;
		this->items[index] = values;
	}*/
}


int HashTable::CalculateHash(int key) {
	return key % this->size;
}

std::stack<int> HashTable::GetItem(int index) {
	return items[index];
}

