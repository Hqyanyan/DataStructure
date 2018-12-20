//
// Created by i_still_mess_up on 2018/11/13.
//
#define B BSTNode<Key, E>*

#include "BST.h"

template <typename Key, typename E>
void BST<Key, E>::clearHelp(B node) {
    if (node == NULL) {
        return;
    }
    clearHelp(node->left());
    clearHelp(node->right());
    delete node;
}

template <typename Key, typename E>
B BST<Key, E>::insertHelp(B node, const Key& k, const E& it) {

}

template <typename Key, typename E>
B BST<Key, E>::deleteMin(B node) {
    if (node->left() == NULL) {
        return node->right();
    }
    else {
        node->setLeft(deleteMin(node->left()));
        return node;
    }
}

template <typename Key, typename E>
B BST<Key, E>::getMin(B node) {
    if (node->left() == NULL) {
        return node;
    }
    return getMin(node->left());
}

template <typename Key, typename E>
B BST<Key, E>::removeHelp(B node, const Key& k) {
    if (node == NULL) {
        return NULL;
    }
    else if (k < node->getKey()) {
        node->setLeft(removeHelp(node->left(), k));
    }
    else if (k > node->getKey()) {
        node->setRight(removeHelp(node->right(), k));
    }
    else {
        B tmp = node;
        if (node->left() == NULL) {
            node = node->right();
            delete tmp;
        }
        else if (node->right() == NULL) {
            node = node->left();
            delete tmp;
        }
        else {
            tmp = getMin(node->right());
            node->setElement(tmp->getElement());
            node->setKey(tmp->getKey());
            node->setRight(deleteMin(node->right()));
            delete tmp;
        }
    }
    return node;
}

template <typename Key, typename E>
E BST<Key, E>::findHelp(B node, const Key& k) const {
    if (node == NULL) {
        return NULL;
    }
    if (k < node->getKey()) {
        return findHelp(node->left(), k);
    }
    else if (k > node->getKey()){
        return findHelp(node->right(), k);
    }
    else {
        return node->getElement();
    }
}

template <typename Key, typename E>
void BST<Key, E>::printHelp(B node, int count) const {
    if (node == NULL) {
        return;
    }
    printHelp(node->left(), count + 1);
    for (int i = 0; i < count; i++) {
        std::cout << "  ";
    }
    std::cout << node->getKey() << '\n';
    printHelp(node->right(), count + 1);
}

template <typename Key, typename E>
BST<Key, E>::BST() {
    root = NULL;
    count = 0;
}

template <typename Key, typename E>
BST<Key, E>::~BST() {
    clearHelp(root);
}

template <typename Key, typename E>
void BST<Key, E>::clear() {
    clearHelp(root);
    root = NULL;
    count = 0;
}

template <typename Key, typename E>
void BST<Key, E>::insert(const Key& k, const E& it) {
    root = insertHelp(root, k, it);
    count++;
}

template <typename Key, typename E>
E BST<Key, E>::remove(const Key& k) {
    E tmp = findHelp(root, k);
    if (tmp != NULL) {
        root = removeHelp(root, k);
        count--;
    }
    return tmp;
}

template <typename Key, typename E>
E BST<Key, E>::removeIt() {
    if (root != NULL) {
        E tmp = root->getElement();
        root = removeHelp(root, root->getKey());
        count--;
        return tmp;
    }
    return NULL;
}

template <typename Key, typename E>
E BST<Key, E>::find(const Key& k) const {
    return findHelp(root, k);
}

template <typename Key, typename E>
int BST<Key, E>::size() {
    return count;
}

template <typename Key, typename E>
void BST<Key, E>::print() const {
    if (root == NULL) {
        std::cout << "The BST is empty." << std::endl;
    }
    else {
        printHelp(root, 0);
    }
}