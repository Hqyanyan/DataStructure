//
// Created by i_still_mess_up on 2018/11/25.
//

#include "BST.h"
#include <cmath>

void BST::clearHelp(Node* node) {
    if (node == NULL) {
        return;
    }
    clearHelp(node->left());
    clearHelp(node->right());
    delete node;
}

Node* BST::insertHelp(Node* node, const int& k) {
    if (node == NULL) {
        return new Node(k);
    }
    if (k < node->getKey()) {
        node->setLeft(insertHelp(node->left(), k));
    }
    else {
        node->setRight(insertHelp(node->right(), k));
    }
    return node;
}

int BST::findHelp(Node* node, const int& k) const {
    if (node == NULL) {
        return -1;
    }
    if (k < node->getKey()) {
        return findHelp(node->left(), k) * 2;
    }
    else if (k > node->getKey()){
        return findHelp(node->right(), k) * 2;
    }
    else {
        return 1;
    }
}

BST::BST() {
    root = NULL;
    count = 0;
}

BST::~BST() {
    clearHelp(root);
}

void BST::clear() {
    clearHelp(root);
    root = NULL;
    count = 0;
}

void BST::insert(const int& k) {
    root = insertHelp(root, k);
    count++;
}

int BST::find(const int& k) const {
    int count = findHelp(root, k);
    if (count < 0) {
        return -1 * (static_cast<int>((log(-count) + 0.5) / log(2)) + 1);
    }
    else {
        return (static_cast<int>((log(count) + 0.5) / log(2)) + 1);
    }
}

int BST::size() {
    return count;
}

