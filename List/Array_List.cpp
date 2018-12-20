//
// Created by i_still_mess_up on 2018/10/2.
//
#include <iostream>
#include "Array_List.h"

template <typename E>
Array_List<E>::Array_List(int size) {
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize];
}

template <typename E>
Array_List<E>::~Array_List() {
    delete [] listArray;
}

template <typename E>
void Array_List<E>::print() const {
    std::cout << '[';
    for (int i = 0; i < listSize - 1; i++) {
        std::cout << listArray[i] << ", ";
    }
    std::cout << listArray[listSize - 1] << ']' << std::endl;
}

template <typename E>
void Array_List<E>::clear() {
    delete [] listArray;
    listSize = curr = 0;
    listArray = new E[maxSize];
}

template <typename E>
void Array_List<E>::insert(const E& it) {
    try {
        if (listSize >= maxSize) {
            throw "顺序表长度不足，添加失败";
        }
        for (int i = listSize; i > curr; i--) {
            listArray[i] = listArray[i - 1];
        }
        listArray[curr] = it;
        listSize++;
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
void Array_List<E>::append(const E& it) {
    try {
        if (listSize >= maxSize) {
            throw "顺序表长度不足，添加失败";
        }
        listArray[listSize++] = it;
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }

}

template <typename E>
E Array_List<E>::remove() {
    try {
        if (curr < 0 || curr >= listSize) {
            throw "No element";
        }
        E it = listArray[curr];
        for (int i = curr; i < listSize - 1; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return it;
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
void Array_List<E>::moveToStart() {
    curr = 0;
}

template <typename E>
void Array_List<E>::moveToEnd() {
    curr = listSize;
}

template <typename E>
void Array_List<E>::prev() {
    if (curr != 0) {
        curr--;
    }
}

template <typename E>
void Array_List<E>::next() {
    if (curr < listSize) {
        curr++;
    }
}


template <typename E>
int Array_List<E>::length() const {
    return listSize;
}

template <typename E>
int Array_List<E>::currPosition() const {
    return curr;
}

template <typename E>
void Array_List<E>::moveToPosition(int position) {
    try {
        if (position < 0 || position >= listSize) {
            throw "Position out of range";
        }
        curr = position;
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
const E& Array_List<E>::getValue() const {
    try {
        if (curr < 0 || curr >= listSize) {
            throw "No current element";
        }
        return listArray[curr];
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}