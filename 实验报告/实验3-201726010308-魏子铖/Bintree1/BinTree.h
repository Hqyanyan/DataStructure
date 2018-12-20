//
// Created by i_still_mess_up on 2018/11/11.
//

#ifndef BINTREE1_BINTREE_H
#define BINTREE1_BINTREE_H

#include <iostream>

struct Node {
    char it;
    Node* lc;
    Node* rc;

    explicit Node(char it, Node* lc = NULL, Node* rc = NULL);
};

class BinTree {
private:
    Node* root;
    int cnt;
    void removeAll(const Node* node);
    void createHelp(Node* &node);
    void orderHelp(const Node* node);
public:
    BinTree();
    ~BinTree();
    void createBinTree();
    void visit(const Node* node);
    void postOrder();
    const int getHeight();
    int count(Node* node);
    const int getCount();
};

#endif //BINTREE1_BINTREE_H
