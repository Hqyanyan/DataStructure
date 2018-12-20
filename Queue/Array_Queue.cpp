//
// Created by i_still_mess_up on 2018/10/24.
//

#include "Array_Queue.h"
#include <iostream>

template <typename E>
Array_Queue<E>::Array_Queue(int size) {
    maxSize = size + 1;
    front = 1;
    rear = 0;
    listArray = new E[maxSize];
}

template <typename E>
Array_Queue<E>::~Array_Queue() {
    delete [] listArray;
}

template <typename E>
void Array_Queue<E>::clear() {
    front = 1;
    rear = 0;
}

template <typename E>
void Array_Queue<E>::enqueue(const E& it) {
    try {
        if ((rear + 2) % maxSize == front) {
            throw "Queue is full";
        }
        rear = (rear + 1) % maxSize;
        listArray[rear] = it;
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
E Array_Queue<E>::dequeue() {
    try {
        if (length() == 0) {
            throw "Queue is empty";
        }
        E it = listArray[front];
        front = (front + 1) % maxSize;
        return it;
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
const E& Array_Queue<E>::frontValue() const {
    try {
        if (length() == 0) {
            throw "Queue is empty";
        }
        return listArray[front];
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
int Array_Queue<E>::length() const {
    return (rear - front + maxSize + 1) % maxSize;
}