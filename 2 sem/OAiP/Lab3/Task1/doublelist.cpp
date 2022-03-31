#include "doublelist.h"
#include <QMessageBox>

DoubleList::DoubleList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

DoubleList::DoubleList(const DoubleList & L)
{
    head = nullptr;
    tail = nullptr;
    count = 0;

    Staff* temp = L.head;

    while (temp != 0) {
        push_back(temp->fullname, temp->number, temp->post, temp->date);
        temp = temp->next;
    }
}

DoubleList::~DoubleList()
{
    clearList();
}

int DoubleList::GetCount()
{
    return count;
}

Staff *DoubleList::getElement(int pos)
{
    Staff *temp = head;
    int i = 1;

    while(i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if(temp == 0)
        return 0;
    else
        return temp;
}

Staff* DoubleList::searchElementBySurname(std::string surname)
{
    Staff *temp = head;
    while(temp != 0)
    {
        std::string tmp_surname = "";
        for (unsigned int i = 0; temp->fullname[i] != ' ' && i < temp->fullname.length(); i++) {
            tmp_surname += temp->fullname[i];
        }
        if (tmp_surname == surname) return temp;
        temp = temp->next;
    }

    if(temp == 0)
        return 0;
    else
        return temp;
}

void DoubleList::erase(int pos)
{

    int i = 1;
    Staff* del = head;

    while (i < pos) {
        del = del->next;
        i++;
    }

    Staff* prev_del = del->prev;
    Staff* next_del = del->next;
    if(prev_del != 0 && count != 1) {
        prev_del->next = next_del;
    }

    if(next_del != 0 && count != 1) {
        next_del->prev = prev_del;
    }


    if(pos == 1)
        head = next_del;
    if(pos == count)
        tail = prev_del;

    delete del;

    count--;
}

void DoubleList::clearList()
{
    while (count != 0) {
        erase(1);
    }
}

void DoubleList::insert(int pos, std::string fullname, int number, std::string post, std::string date)
{
    if (pos == count + 1){
        push_back(fullname, number, post, date);
        return;
    } else if (pos == 1) {
        push_front(fullname, number, post, date);
        return;
    }

    int i = 1;

    Staff* ins = head;
    while (i < pos) {
        ins = ins->next;
        i++;
    }

    Staff* prev_ins = ins->prev;

    Staff* temp = new Staff;

    temp->fullname = fullname;
    temp->number = number;
    temp->post = post;
    temp->date = date;

    if (prev_ins != 0 && count != 1) {
        prev_ins->next = temp;
    }

    temp->next = ins;
    temp->prev = prev_ins;
    ins->prev = temp;

    count++;
}

void DoubleList::push_back(std::string fullname, int number, std::string post, std::string date)
{
    Staff* temp = new Staff;
    temp->next = 0;

    temp->fullname = fullname;
    temp->number = number;
    temp->post = post;
    temp->date = date;

    temp->prev = tail;

    if(tail != 0) tail->next = temp;

    if(count == 0)
        head = tail = temp;
    else
        tail = temp;

    count++;
}

void DoubleList::pop_back()
{
    erase(GetCount());
}

void DoubleList::push_front(std::string fullname, int number, std::string post, std::string date)
{
    Staff * temp = new Staff;
    temp->prev = 0;

    temp->fullname = fullname;
    temp->number = number;
    temp->post = post;
    temp->date = date;

    temp->next = head;

    if(head != 0) head->prev = temp;

    if(count == 0)
        head = tail = temp;
    else
        head = temp;

    count++;
}

void DoubleList::pop_front()
{
    erase(1);
}
