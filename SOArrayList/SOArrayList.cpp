//
// Created by i_still_mess_up on 2018/12/16.
//

#include "SOArrayList.h"

void SOArrayList::renovate(const int index) {
    if (index == 0) {
        return;
    }
    char temp1 = listArray[index];
    listArray[index] = listArray[index - 2];
    listArray[index - 2] = temp1;
    char temp2 = listArray[index + 1];
    listArray[index + 1] = listArray[index - 1];
    listArray[index - 1] = temp2;
}

SOArrayList::SOArrayList(const int size) {
    maxSize = size;
    currSize = 0;
    listArray = new char[size];
}

SOArrayList::~SOArrayList() {
    delete [] listArray;
}

void SOArrayList::append(const char k1, const char k2) {
    listArray[currSize++] = k1;
    listArray[currSize++] = k2;
}

int SOArrayList::find(const char k1, const char k2) {
    int index = 0;
    bool flag = false;
    for (int i = 0; i < maxSize; i += 2) {
        if (listArray[i] == k1 && listArray[i + 1] == k2) {
            index = i;
            flag = true;
            break;
        }
    }
    if (index == 0 && !flag) {
        return maxSize;
    }
    renovate(index);
    return index;
}

void SOArrayList::print() {
    for (int i = 0; i < maxSize; i += 2) {
        std::cout << listArray[i] << listArray[i + 1] << ' ';
    }
}
