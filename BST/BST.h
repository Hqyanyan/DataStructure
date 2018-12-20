//
// Created by i_still_mess_up on 2018/11/13.
//

#ifndef BST_BST_H
#define BST_BST_H
#define B BSTNode<Key, E>*

#include "BSTNode.h"

template <typename Key, typename E>
class BST : public BSTNode<Key, E> {
private:
    B root;
    int count;

    void clearHelp(B);
    B insertHelp(B, const Key&, const E&);
    B deleteMin(B);
    B getMin(B);
    B removeHelp(B, const Key&);
    E findHelp(B, const Key&) const;
    void printHelp(B, int) const;

public:
    BST();
    ~BST();

    void clear();
    void insert(const Key&, const E&);
    E remove(const Key&);
    E removeIt();
    E find(const Key&) const;
    int size();
    void print() const;
};


#endif //BST_BST_H
