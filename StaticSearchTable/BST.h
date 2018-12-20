//
// Created by i_still_mess_up on 2018/11/25.
//

#ifndef STATICSEARCHTABLE_BST_H
#define STATICSEARCHTABLE_BST_H

#include "Node.h"

class BST : public Node {
private:
    Node* root;
    int count;

    void clearHelp(Node*);
    Node* insertHelp(Node*, const int&);
    int findHelp(Node*, const int&) const;

public:
    BST();
    ~BST();

    void clear();
    void insert(const int&);
    int find(const int&) const;
    int size();
};
#endif //STATICSEARCHTABLE_BST_H
