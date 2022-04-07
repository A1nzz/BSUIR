#ifndef STACK_H
#define STACK_H

#include <cassert>

template <typename T>
class Stack {
private:
    const int size = 1000;
    T A[1000];
    int top = 0;
public:

    bool isEmpty() {
        if (top == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(T value) {
        if (top == size) {
            assert(top < size);
            return;
        }
        else {
            top++;
            A[top] = value;
        }
    }

    void pop() {
        if (isEmpty()) {
            assert(top > 0);
            return;
        }
        else {
            top--;
        }
    }

    T popAndGet() {
        if (isEmpty()) {
            assert(top > 0);
            return 0;
        }
        else {
            return A[top--];
        }
    }

    T getTop() {
        if (isEmpty()) {
            return 0;
        }
        else {
            return A[top];
        }
    }
};
#endif // STACK_H
