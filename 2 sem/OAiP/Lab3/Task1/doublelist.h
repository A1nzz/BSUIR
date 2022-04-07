#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <QMessageBox>

#include "staff.h"

class DoubleList
{
private:
    Staff* head = nullptr;
    Staff* tail = nullptr;
    int count;
public:
    DoubleList();
    DoubleList(const DoubleList&);
    ~DoubleList();
    int GetCount();
    Staff* getElement(int pos);
    Staff* searchElementBySurname(std::string surname);
//    void qsortElement();
    void erase(int pos);
    void clearList();
    void insert(int pos, std::string fullname, int number, std::string post, std::string date);
    void push_back(std::string fullname, int number, std::string post, std::string date);
    void pop_back();
    void push_front(std::string fullname, int number, std::string post, std::string date);
    void pop_front();

    void swap ( int* a, int* b );

    Staff* partition(Staff *l, Staff *h);

    void _quickSort(Staff* l, Staff *h);

    void quickSort();
};

#endif // DOUBLELIST_H
