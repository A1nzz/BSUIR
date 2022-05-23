#pragma once
template <typename T>
class Queue{
private:
	T* data;
	size_t front;
	size_t rear;
	size_t size;
public:
	Queue() {
		data = new T[10];
		front = 0;
		rear = 0;
		size = 10;
	}
	Queue(size_t size) {
		data = new T[size];
		front = 0;
		rear = 0;
		this->size = size;
	}	
	Queue(const Queue& other) {
		data = new T[other.size];
		front = other.front;
		rear = other.rear;
		this->size = other.size;
		for (size_t i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	Queue& operator=(const Queue& other) {
		if (this != &other) {
			delete[] data;
			data = new T[other.size];
			front = other.front;
			rear = other.rear;
			this->size = other.size;
			for (size_t i = 0; i < size; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	~Queue() {
		delete[] data;
	}
	void push(T value) {
		if (rear == size) {
			rear = 0;
		}
		data[rear] = value;
		rear++;
	}
	T pop() {
		if (front == size) {
			front = 0;
		}
		T value = data[front];
		front++;
		return value;
	}

	bool isEmpty() {
		return front == rear;
	}

	size_t getSize() {
		return size;
	}
	
	
};
