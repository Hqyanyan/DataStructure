//
// Created by i_still_mess_up on 2018/11/25.
//

#include "Node.h"

Node::Node() {
    lc = rc = NULL;
}

Node::Node(int k, Node* lc, Node* rc) {
    this->k = k;
    this->lc = lc;
    this->rc = rc;
}

int& Node::getKey() {
    return k;
}

void Node::setKey(const int& k) {
    this->k = k;
}

bool Node::isLeaf() {
    return (lc == NULL) && (rc == NULL);
}

Node* Node::left() const {
    return lc;
}

void Node::setLeft(Node* lc) {
    this->lc = lc;
}

Node* Node::right() const {
    return rc;
}

void Node::setRight(Node* rc) {
    this->rc = rc;
}
