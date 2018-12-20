//
// Created by i_still_mess_up on 2018/11/7.
//

#include <cmath>
#include "BinTree.h"

Node::Node(char it, Node* lc, Node* rc) {
    this->it = it;
    this->lc = lc;
    this->rc = rc;
}

void BinTree::removeAll(const Node* node) {
    if (node) {
        removeAll(node->lc);
        removeAll(node->rc);
        delete node;
    }
}

void BinTree::createHelp(Node* &node) {
    char tmp;
    std::cin >> tmp;
    if (tmp == '/') {
        node = NULL;
    }
    else {
        node = new Node(tmp);
        createHelp(node->lc);
        createHelp(node->rc);
        cnt++;
    }
}

void BinTree::convertHelp(Node* &root) {
    if(root == NULL)
        return;
    if(root->rc != NULL) {
        if(root->lc == NULL) {
            root->lc=root->rc;
            convertHelp(root->lc);
        }
        else {
            convertHelp(root->lc);
            root->lc->rc=root->rc;
            convertHelp(root->lc->rc);
        }
        root->rc = NULL;
        return;
    }
    convertHelp(root->lc);
}

void BinTree::orderHelp(const Node* node) {
    if (node) {
        orderHelp(node->lc);
        orderHelp(node->rc);
        visit(node);
    }
}

BinTree::BinTree() {
    root = NULL;
    cnt = 0;
}

BinTree::~BinTree() {
    removeAll(root);
}

void BinTree::createBinTree() {
    createHelp(root);
}

void BinTree::visit(const Node* node) {
    std::cout << node->it << ' ';
}

void BinTree::postOrder() {
    orderHelp(root);
}

const int BinTree::getHeight() {
    return count(root);
}

int BinTree::count(Node* node) {
    if (node == NULL)
        return 0;
    return std::max(count(node->lc), count(node->rc)) + 1;
}

void BinTree::convert() {
    convertHelp(root);
}

const int BinTree::getCount() {
    return cnt;
}

