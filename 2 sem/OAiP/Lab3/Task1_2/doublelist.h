#ifndef DOUBLELIST_H
#define DOUBLELIST_H


#include "vector.h"

struct Product {
    std::string name = "Milk";
    int count = 2;
    int price = 100;
    std::string date = "20.01.2001";
};
class DoubleList {
private:
    struct Node {
        Product product;
        int next = -1;
        int prev = -1;
        Node() {

        }
        Node(Product pr, int n, int p)
            :product(pr), next(n), prev(p)
        {
        };
    };
    Vector<Node> nodes;
    int head;
    int tail;
    int size;
public:
    DoubleList() {
        head = -1;
        tail = -1;
        size = 0;
    }


    ~DoubleList() {
        listClear();
    }

    void listClear() {
        while (size != 0) {
            remove(0);
        }
    }
    int getSize() {
        return size;
    }

    void add(Product product) {
        if (size == 0) {
            head = 0;
            tail = 0;
            nodes.push_back(Node(product, -1, -1));
            size++;
        }
        else {
            nodes.push_back(Node{ product, -1, tail });
            nodes[tail].next = nodes.size() - 1;
            tail = nodes.size() - 1;
            size++;
        }


    }

    void pop() {
        if (size == 0) {
            return;
        }
        if (size == 1) {
            head = -1;
            tail = -1;
            size = 0;
            return;
        }
        int index = tail;
        tail = nodes[index].prev;
        nodes[tail].next = -1;
        nodes.pop_back();
        size--;
    }

    void remove(int index) {
        if (size == 1) {
            head = -1;
            tail = -1;
            nodes.remove(index);
            size--;
        }
        else if (index == head) {
            nodes.remove(index);
            tail = nodes.size() - 1;
            int i = index + 1;
            while (i < nodes.size()) {
                nodes[i].prev--;
                nodes[i].next--;
                i++;
            }
            nodes[index].prev = -1;
            nodes[index].next = 1;
            nodes[tail].next = -1;
            size--;
        }
        else if (index == tail) {
            nodes.remove(index);
            tail = nodes.size() - 1;
            nodes[tail].next = -1;
            size--;
        }
        else {
            nodes.remove(index);
            tail = nodes.size() - 1;
            int i = index + 1;
            while (i < nodes.size()) {
                nodes[i].prev--;
                nodes[i].next--;
                i++;
            }
            nodes[tail].next = -1;
            size--;
        }
    }

    void insert(int index, Product product) {
        if (size == 0) {
            head = 0;
            tail = 0;
            nodes.push_back(Node(product, -1, -1 ));
            size++;
        }
        else if (index == 0) {
            nodes.insert(index, Node(product, 1, -1));
            nodes[nodes.size() - 1].next = nodes.size();
            nodes[1].prev = 0;
            tail = nodes.size() - 1;
            int i = index + 1;
            while (i < nodes.size()) {
                nodes[i].prev++;
                nodes[i].next++;
                i++;
            }
            nodes[nodes.size() - 1].next = -1;
            size++;
        }
        else if (index == size) {
            nodes.push_back(Node(product, -1, tail));
            nodes[tail].next = nodes.size() - 1;
            tail = nodes.size() - 1;
            size++;
        }
        else if (index == size - 1) {
            nodes.insert(index, Node(product, size, nodes[index].prev ));
            tail = nodes.size() - 1;
            int i = index + 1;
            while (i < nodes.size()) {
                nodes[i].next++;
                nodes[i].prev++;
                i++;
            }
            nodes[nodes.size() - 1].next = -1;
            size++;
        }
        else {
            nodes.insert(index, Node(product, nodes[index].next, nodes[index].prev ));
            tail = nodes.size() - 1;
            int i = index + 1;
            while (i < nodes.size()) {
                nodes[i].next++;
                nodes[i].prev++;
                i++;
            }
            nodes[nodes.size() - 1].next = -1;
            size++;
        }


    }

    int getHead() {
        return head;
    }
    int getTail() {
        return tail;
    }

    Product getProduct(int index) {
        return nodes[index].product;
    }

    void print() {
        int index = head;
        while (index != -1) {
            std::cout << nodes[index].product.name << " " << nodes[index].product.count << " " << nodes[index].product.price << " " << nodes[index].product.date << std::endl;
            index = nodes[index].next;
        }
    }

    void _quickSort(Vector<Node> array, int low, int high)
    {
        int i = low;
        int j = high;
        Node pivot = array[(i + j) / 2];
        Node temp;
        int tempPr;
        int tempNe;


        while (i <= j)
        {
            while (array[i].product.price < pivot.product.price)
                i++;
            while (array[j].product.price > pivot.product.price)
                j--;
            if (i <= j)
            {
                temp = array[i];
                tempPr = array[i].prev;
                tempNe = array[i].next;
                array[i] = array[j];
                array[i].prev = array[j].prev;
                array[i].next = array[j].next;
                array[j] = temp;
                array[j].next = tempNe;
                array[j].prev = tempPr;
                i++;
                j--;
            }
        }
        if (j > low)
            _quickSort(array, low, j);
        if (i < high)
            _quickSort(array, i, high);
    }
    void quickSort() {
        _quickSort(nodes, head, tail);
    }
};

#endif // DOUBLELIST_H
