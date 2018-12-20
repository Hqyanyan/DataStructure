//
// Created by i_still_mess_up on 2018/11/13.
//

#ifndef BST_BSTNODE_H
#define BST_BSTNODE_H

#include <iostream>
#include "Node.h"

template <typename Key, typename E>
class BSTNode : public Node<E> {
private:
    Key k;
    E it;
    BSTNode* lc;
    BSTNode* rc;

public:
    BSTNode();
    explicit BSTNode(Key k, E it, BSTNode* lc = NULL, BSTNode* rc = NULL);
    ~BSTNode() = default;

    // Functions to set and return the value and key
    E& getElement();
    void setElement(const E&);
    Key& getKey();
    void setKey(const Key&);
    bool isLeaf();

    // Functions to set and return the children
    inline BSTNode* left() const;
    void setLeft(Node<E>*);
    inline BSTNode* right() const;
    void setRight(Node<E>*);

};

#endif //BST_BSTNODE_H
