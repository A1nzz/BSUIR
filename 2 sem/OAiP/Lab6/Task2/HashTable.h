#pragma once
#include <stack>

class HashTable {
public:
	HashTable(int size);
	~HashTable();
	void Insert(int value);
	int CalculateHash(int key);
	int Search(int value);
	void Remove(int value);
	std::stack<int> GetItem(int index);
private:
	int size;
	int count;
	std::stack<int>* items;
}; 

