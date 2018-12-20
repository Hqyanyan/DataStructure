//
// Created by i_still_mess_up on 2018/11/25.
//

#ifndef STATICSEARCHTABLE_NODE_H
#define STATICSEARCHTABLE_NODE_H

#include <iostream>

class Node {
private:
    int k;
    Node* lc;
    Node* rc;

public:
    Node();
    explicit Node(int, Node* lc = NULL, Node* rc = NULL);
    ~Node() = default;

    // Functions to set and return the key
    int& getKey();
    void setKey(const int&);
    bool isLeaf();

    // Functions to set and return the children
    Node* left() const;
    void setLeft(Node*);
    Node* right() const;
    void setRight(Node*);

};


#endif //STATICSEARCHTABLE_NODE_H
