#include "DoubleList.h"

DoubleList::DoubleList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}
DoubleList::DoubleList(const DoubleList& L)
{
    head = nullptr;
    tail = nullptr;
    count = 0;

    std::shared_ptr<Node> temp = L.head;

    while (temp != 0) {
        push_back(temp->data);
        temp = temp->next;
    }
}



DoubleList::~DoubleList()
{
    clearList();
}


size_t DoubleList::GetCount()
{
    return count;
}

int DoubleList::getElement(size_t pos)
{
    std::shared_ptr<Node> temp = head;
    int i = 1;

    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
        return 0;
    else
        return temp->data;
}
void DoubleList::erase(size_t pos)
{

    int i = 1;
    std::shared_ptr<Node> del = head;

    while (i < pos) {
        del = del->next;
        i++;
    }

    std::weak_ptr<Node> prev_del = del->prev;
    std::shared_ptr<Node> next_del = del->next;
    if (prev_del.lock() != 0 && count != 1) {
        prev_del.lock()->next = next_del;
    }

    if (next_del != 0 && count != 1) {
        next_del->prev = prev_del;
    }


    if (pos == 1)
        head = next_del;
    if (pos == count)
        tail = prev_del.lock();

    //delete del;

    count--;
}

void DoubleList::clearList()
{
    while (count != 0) {
        erase(1);
    }
}

void DoubleList::insert(size_t pos, int val)
{
    if (pos == count + 1) {
        push_back(val);
        return;
    }
    else if (pos == 1) {
        push_front(val);
        return;
    }

    int i = 1;

    std::shared_ptr<Node> ins = head;
    while (i < pos) {
        ins = ins->next;
        i++;
    }

    std::weak_ptr<Node> prev_ins = ins->prev;

    std::shared_ptr<Node> temp = std::make_shared<Node>();
    temp->data = val;

    if (prev_ins.lock() != 0 && count != 1) {
        prev_ins.lock()->next = temp;
    }

    temp->next = ins;
    temp->prev = prev_ins;
    ins->prev = temp;

    count++;
}

void DoubleList::push_back(int val)
{
    std::shared_ptr<Node> temp = std::make_shared<Node>();
    temp->next = 0;
    temp->data = val;
    temp->prev = tail;

    if (tail != 0) tail->next = temp;

    if (count == 0)
        head = tail = temp;
    else
        tail = temp;

    count++;
}

void DoubleList::pop_back()
{
    erase(GetCount());
}


void DoubleList::push_front(int val)
{
    std::shared_ptr<Node> temp = std::make_shared<Node>();
    temp->prev.lock() = 0;
    temp->data = val;
    temp->next = head;

    if (head != 0) head->prev = temp;

    if (count == 0)
        head = tail = temp;
    else
        head = temp;

    count++;
}

void DoubleList::pop_front()
{
    erase(1);
}

std::shared_ptr<DoubleList::Node> DoubleList::getMax() {
	std::shared_ptr<Node> temp = head;
    std::shared_ptr<Node> max = temp;
	
    while (temp != 0) {
        if (temp->data > max->data)
			max = temp;
		temp = temp->next;
    }
    return max;
}
std::shared_ptr<DoubleList::Node> DoubleList::getMin() {
    std::shared_ptr<Node> temp = head;
    std::shared_ptr<Node> min = temp;

    while (temp != 0) {
        if (temp->data < min->data)
            min = temp;
        temp = temp->next;
    }
    return min;
}

int DoubleList::getMaxIndex() {
    std::shared_ptr<Node> temp = head;
    std::shared_ptr<Node> max = head;
    int maxInd = 1;
    int i = 1;
    while (temp != 0) {
        if (temp->data > max->data) {
            max = temp;
            maxInd = i;
        }	
        temp = temp->next;
        i++;
    }
    return maxInd;
}
int DoubleList::getMinIndex() {
    std::shared_ptr<Node> temp = head;
    std::shared_ptr<Node> min = head;
    int minInd = 1;
    int i = 1;
    while (temp != 0) {
        if (temp->data < min->data) {
            min = temp;
            minInd = i;
        }
        temp = temp->next;
        i++;
    }
    return minInd;
}



DoubleList* DoubleList::make_circle() {


    std::shared_ptr<Node> max = getMax();
    std::shared_ptr<Node> min = getMin();
    int minInd = getMinIndex();
    int maxInd = getMaxIndex();
    DoubleList* newList = new DoubleList();

    if (minInd < maxInd) {
        for (int i = minInd; i <= maxInd; i++) {
            newList->push_back(getElement(i));
        }
        for (int i = minInd; i <= maxInd; i++) {
            erase(minInd);
        }
        head->prev = tail;
        tail->next = head;
    }
    else {
        for (int i = maxInd; i <= minInd; i++) {
            newList->push_back(getElement(i));
        }
        for (int i = maxInd; i <= minInd; i++) {
            erase(maxInd);
        }
        head->prev = tail;
        tail->next = head;
    }
    if (newList != nullptr) {
        make_rings(newList);
        return newList;
    }
    else {
        return nullptr;
    }
   
}

void DoubleList::make_rings(DoubleList* list) {
    list->head->prev = list->tail;
    list->tail->next = list->head;
}

std::shared_ptr<DoubleList::Node> DoubleList::getNode(size_t pos) {
    std::shared_ptr<Node> temp = head;
    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
        return 0;
    else
        return temp;
}


size_t DoubleList::getIndex(std::shared_ptr<Node> ptr) {
    std::shared_ptr<Node> temp = head;
    int i = 1;
    while (temp != ptr) {
        temp = temp->next;
        i++;
    }
    return i;
}
   /* if (getMinIndex() < getMaxIndex()) {
        if (getMinIndex() == 1 && getMaxIndex() == count) {
            head->prev = tail;
			tail->next = head;
        }
        else if (getMinIndex() == 1) {
            DoubleList* newList = new DoubleList();
            for (int i = getMinIndex(); i <= getMaxIndex(); i++) {
                newList->push_back(getElement(i));
            }
            for (int i = getMinIndex(); i <= getMaxIndex(); i++) {
                erase(getMinIndex());
            }
            max->next->prev = tail;
            tail->next = max->next;

          
        }
        else if (getMaxIndex() == count) {
            min->prev.lock()->next = head;
            head->prev = min->prev;
            DoubleList* newList = new DoubleList();
            for (int i = getMinIndex(); i <= getMaxIndex(); i++) {
                newList->push_back(getElement(i));
            }
            for (int i = getMinIndex(); i <= getMaxIndex(); i++) {
                erase(getMinIndex());
            }
        }
        else {
            max->next->prev = min->prev.lock();
            min->prev.lock()->next = max->next;
            head->prev = tail;
            tail->next = head;
            DoubleList* newList = new DoubleList();
            for (int i = getMinIndex(); i <= getMaxIndex(); i++) {
                newList->push_back(getElement(i));
            }
            for (int i = getMinIndex(); i <= getMaxIndex(); i++) {
                erase(getMinIndex());
            }
        }
    }
    else {
        if (getMaxIndex() == 0 && getMinIndex() == count) {
            head->prev = tail;
            tail->next = head;
        }
        else if (getMaxIndex() == 0) {
            min->next->prev = tail;
            tail->next = min->next;
            DoubleList* newList = new DoubleList();
            for (int i = getMaxIndex(); i <= getMinIndex(); i++) {
                newList->push_back(getElement(i));
            }
            for (int i = getMaxIndex(); i <= getMinIndex(); i++) {
                erase(getMaxIndex());
            }
        }
        else if (getMinIndex() == count) {
            max->prev.lock()->next = head;
            head->prev = min->prev;
            DoubleList* newList = new DoubleList();
            for (int i = getMaxIndex(); i <= getMinIndex(); i++) {
                newList->push_back(getElement(i));
            }
            for (int i = getMaxIndex(); i <= getMinIndex(); i++) {
                erase(getMaxIndex());
            }
        }
        else {
            min->next->prev = max->prev.lock();
            max->prev.lock()->next = min->next;
            head->prev = tail;
            tail->next = head;
            DoubleList* newList = new DoubleList();
            for (int i = getMaxIndex(); i <= getMinIndex(); i++) {
                newList->push_back(getElement(i));   
            }
            for (int i = getMaxIndex(); i <= getMinIndex(); i++) {
                erase(getMaxIndex());
            }    
        }
    }*/
	
	/*std::shared_ptr<Node> max = getMax();
    std::shared_ptr<Node> min = getMin();
    if (getMinIndex() < getMaxIndex()) {
        
        if (getMinIndex() == 1 && getMaxIndex() == GetCount()) {
            head->prev = tail;
            tail->next = head;
        }
        else if (getMinIndex() == 1) {
            min->next->prev = max->prev;
            max->prev.lock()->next = min->next;
            tail->next = max->next;
            max->next->prev = tail;
            
        }
        else if (getMaxIndex() == GetCount()) {
            min->next->prev = max->prev;
            max->prev.lock()->next = min->next;
            head->prev = min->prev;
			min->prev.lock()->next = head;
            
        }
        else {
            min->prev.lock()->next = max->next;
            max->next->prev = min->prev.lock();

            min->next->prev = max->prev;
            max->prev.lock()->next = min->next;
            head->prev = tail;
            tail->next = head;
            
          
        }     
    }
    else {
        if (getMaxIndex() == 1 && getMinIndex() == GetCount()) {
            head->prev = tail;
            tail->next = head;		
        }
        else if (getMaxIndex() == 1) {
            max->next->prev = min->prev;
            min->prev.lock()->next = max->next;
            tail->next = min->next;
			min->next->prev = tail;
			
        }
        else if (getMinIndex() == GetCount()) {
            max->next->prev = min->prev;
            min->prev.lock()->next = max->next;
			head->prev = max->prev;
			max->prev.lock()->next = head;
			
		}
		else {
            max->prev.lock()->next = min->next;
            min->next->prev = max->prev;
            max->next->prev = min->prev;
            min->prev.lock()->next = max->next;
            head->prev = tail;
            tail->next = head;
            
        }	
    } */

