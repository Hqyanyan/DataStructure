//
// Created by i_still_mess_up on 2018/11/7.
//

#ifndef BINTREE2_BINTREE_H
#define BINTREE2_BINTREE_H

#include <iostream>

struct Node {
    char it;
    Node* lc;
    Node* rc;

    explicit Node(char it, Node* lc = NULL, Node* rc = NULL);
};


class BinTree {
private:
    int cnt;
    Node* root;
    void removeAll(const Node* node);
    void createHelp(Node* &node);
    void convertHelp(Node* &node);
    void orderHelp(const Node* node);

public:
    BinTree();
    ~BinTree();
    void createBinTree();
    void convert();
    void visit(const Node* node);
    void postOrder();
    const int getHeight();
    const int getCount();
    int count(Node* node);
};



#endif //BINTREE2_BINTREE_H
