//
// Created by i_still_mess_up on 2018/12/16.
//

#ifndef SOARRAYLIST_SOARRAYLIST_H
#define SOARRAYLIST_SOARRAYLIST_H

#include <iostream>

class SOArrayList {
private:
    int maxSize;
    int currSize;
    char* listArray;
    void renovate(int);
public:
    explicit SOArrayList(int);
    ~SOArrayList();

    void append(char, char);
    int find(char, char);
    void print();
};


#endif //SOARRAYLIST_SOARRAYLIST_H