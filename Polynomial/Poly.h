//
// Created by i_still_mess_up on 2018/10/23.
//
#ifndef POLYNOMIAL_POLY_H
#define POLYNOMIAL_POLY_H

#include <iostream>
struct Node {
    int index;
    double coef;
    Node* next;

    explicit Node(double c, int i, Node* ptr = NULL);
    explicit Node(Node* ptr = NULL);
};

class Poly {
private:
    Node* head;
    Node* curr;
    Node* tail;

    void init() {
        curr = tail = head = new Node;
        tail = new Node(-1, -1);
        head -> next = tail;
    }
    void removeAll() {
        while (head != NULL) {
            curr = head;
            head = head -> next;
            delete curr;
        }
    }

public:
    Poly();
    ~Poly();
    void insert(const double&, const int&);
    void next();
    bool hasNext();
    void clear();
    void print() const;

    double getCoef();
    int getIndex();

};

#endif //POLYNOMIAL_POLY_H
