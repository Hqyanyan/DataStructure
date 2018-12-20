//
// Created by i_still_mess_up on 2018/11/13.
//

#include "BSTNode.h"

template <typename Key, typename E>
BSTNode<Key, E>::BSTNode() {
    lc = rc = NULL;
}

template <typename Key, typename E>
BSTNode<Key, E>::BSTNode(Key k, E it, BSTNode* lc, BSTNode* rc) {
    this->k = k;
    this->it = it;
    this->lc = lc;
    this->rc = rc;
}

template <typename Key, typename E>
E& BSTNode<Key, E>::getElement() {
    return it;
}

template <typename Key, typename E>
void BSTNode<Key, E>::setElement(const E& it) {
    this->it = it;
}

template <typename Key, typename E>
Key &BSTNode<Key, E>::getKey() {
    return k;
}

template <typename Key, typename E>
void BSTNode<Key, E>::setKey(const Key& k) {
    this->k = k;
}

template <typename Key, typename E>
bool BSTNode<Key, E>::isLeaf() {
    return (lc == NULL) && (rc == NULL);
}

template <typename Key, typename E>
BSTNode<Key, E>* BSTNode<Key, E>::left() const {
    return lc;
}

template <typename Key, typename E>
void BSTNode<Key, E>::setLeft(Node<E>* lc) {
    this->lc = (BSTNode*) lc;
}

template <typename Key, typename E>
BSTNode<Key, E>* BSTNode<Key, E>::right() const {
    return rc;
}

template <typename Key, typename E>
void BSTNode<Key, E>::setRight(Node<E>* rc) {
    this->rc = (BSTNode*) rc;
}
