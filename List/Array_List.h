//
// Created by i_still_mess_up on 2018/10/2.
//

#ifndef LIST_ARRAY_LIST_H
#define LIST_ARRAY_LIST_H

#include "List.h"


template <typename E>
class Array_List : public List<E> {
private:
    int maxSize;
    int listSize;
    int curr;
    E* listArray;

public:
    explicit Array_List(int size = defaultSize);
    ~Array_List();

    void print() const;
    void clear();
    void insert(const E&);
    void append(const E&);
    E remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length() const;
    int currPosition() const;
    void moveToPosition(int);
    const E& getValue() const;
};


#endif //LIST_ARRAY_LIST_H

