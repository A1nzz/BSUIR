#ifndef STACK_H
#define STACK_H

#include <cassert>

class Stack {
private:
    const int size = 1000;
    char A[1000];
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

    void push(char value) {
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

    char getTop() {
        if (isEmpty()) {
            return 0;
        }
        else {
            return A[top];
        }
    }
};
#endif // STACK_H
