#pragma once
#include <memory>
class DoubleList
{
private:
    struct Node {
		std::shared_ptr<Node> next;
		std::weak_ptr<Node> prev;
		int data;
    };	
	std::shared_ptr<Node> head = nullptr;
	std::shared_ptr<Node> tail = nullptr;
	size_t count;
  
public:
	DoubleList();
	DoubleList(const DoubleList&);
	~DoubleList();
	size_t GetCount();
	int getElement(size_t pos);
	void erase(size_t pos);
	void clearList();
	void insert(size_t pos, int val);
	void push_back(int val);
	void pop_back();
	void push_front(int val);
	void pop_front();
	std::shared_ptr<Node> getMax();
	std::shared_ptr<Node> getMin();
	int getMaxIndex();
	int getMinIndex();
	DoubleList* make_circle();
	void make_rings(DoubleList* list);
	std::shared_ptr<Node> getNode(size_t pos);
	size_t getIndex(std::shared_ptr<Node> ptr);
};
