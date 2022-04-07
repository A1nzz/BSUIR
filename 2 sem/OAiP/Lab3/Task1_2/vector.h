#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
template <typename T>
class Vector{
public:
    Vector();
    Vector(int size);
    Vector(const Vector<T>& other);
    ~Vector();
    Vector<T>& operator=(const Vector<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;
    int size() const;
    void push_back(const T& value);
    void pop_back();
    void clear();
    void resize(int newSize);
    void reserve(int newCapacity);
    void insert(int index, const T& value);
    void remove(int index);
    void swap(Vector<T>& other);
    void sort();
    void reverse();
private:
    T* m_data;
    int m_size;
    int m_capacity;
};

template <typename T>
Vector<T>::Vector(){
    m_size = 0;
    m_capacity = 0;
    m_data = nullptr;
}
template <typename T>
Vector<T>::Vector(int size){
    m_size = size;
    m_capacity = size;
    m_data = new T[size];
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other){
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new T[other.m_capacity];
    for(int i = 0; i < other.m_size; i++){
        m_data[i] = other.m_data[i];
    }
}
template <typename T>
Vector<T>::~Vector(){
    delete[] m_data;
    m_data = nullptr;
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this != &other){
        delete[] m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[other.m_capacity];
        for(int i = 0; i < other.m_size; i++){
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}
template <typename T>
T& Vector<T>::operator[](int index){
    return m_data[index];
}
template <typename T>
const T& Vector<T>::operator[](int index) const{
    return m_data[index];
}
template <typename T>
int Vector<T>::size() const{
    return m_size;
}
template <typename T>
void Vector<T>::push_back(const T& value){
    if (m_size == 0) {
        reserve(1);
    } else if(m_size == m_capacity){
        reserve(m_capacity * 2);
    }
    m_data[m_size] = value;
    m_size++;
}
template <typename T>
void Vector<T>::pop_back(){
    m_size--;
}
template <typename T>
void Vector<T>::clear(){
    m_size = 0;
}
template <typename T>
void Vector<T>::resize(int newSize){
    if(newSize > m_capacity){
        this->reserve(newSize);
    }
    m_size = newSize;
}
template <typename T>
void Vector<T>::reserve(int newCapacity){

    if(newCapacity > m_capacity){
        T* newData = new T[newCapacity];
        //Vector<T> newData(newCapacity);
        for(int i = 0; i < m_size; i++){
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }
}
template <typename T>
void Vector<T>::insert(int index, const T& value){
    if(index > m_size){
        throw std::out_of_range("Index out of range");
    }
    if (m_size == 0) {
        reserve(1);
    } else if(m_size == m_capacity){
        this->reserve(m_capacity * 2);
    }
    for(int i = m_size; i > index; i--){
        m_data[i] = m_data[i - 1];
    }
    m_data[index] = value;
    m_size++;
}
template <typename T>
void Vector<T>::remove(int index){
    if(index >= m_size){
        throw std::out_of_range("Index out of range");
    }
    for(int i = index; i < m_size - 1; i++){
        m_data[i] = m_data[i + 1];
    }
    m_size--;
}
template <typename T>
void Vector<T>::swap(Vector<T>& other){
    T* temp = m_data;
    m_data = other.m_data;
    other.m_data = temp;
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
    int tempCapacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = tempCapacity;
}
template <typename T>
void Vector<T>::sort(){
    std::sort(m_data, m_data + m_size);
}
template <typename T>
void Vector<T>::reverse(){
    for(int i = 0; i < m_size / 2; i++){
        T temp = m_data[i];
        m_data[i] = m_data[m_size - i - 1];
        m_data[m_size - i - 1] = temp;
    }
}


#endif // VECTOR_H
