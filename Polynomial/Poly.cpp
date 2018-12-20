//
// Created by i_still_mess_up on 2018/10/23.
//

#include "Poly.h"

Node::Node(double c, int i, Node *ptr) {
    coef = c;
    index = i;
    next = ptr;
}

Node::Node(Node *ptr) {
    index = 2147483647;
    coef = 999999;
    next = ptr;
}

Poly::Poly() {
    init();
}

Poly::~Poly() {
    removeAll();
}

void Poly::insert(const double & coef, const int & index) {
    Node* tmp = head;
    if (tmp -> next == tail)
        head -> next = new Node(coef, index, tail);
    else {
        while (tmp -> next -> index > index) {
            tmp = tmp -> next;
        }
        tmp -> next = new Node(coef, index, tmp -> next);
    }
}

void Poly::next() {
    if (curr -> next != tail)
        curr =  curr -> next;
}

bool Poly::hasNext() {
    return curr -> next != tail;
}

void Poly::clear() {
    removeAll();
    init();
}

double Poly::getCoef() {
    return curr -> next -> coef;
}

int Poly::getIndex() {
    return curr -> next -> index;
}

void Poly::print() const {
    Node* tmp = head;
    std::cout << "A(x) + B(x) = ";
    if ((int)tmp -> next -> coef == 1) {
        if (tmp -> next -> index == 0)
            std::cout << '1';
    }
    else if ((int)tmp -> next -> coef == -1) {
        std::cout << '-';
    }
    else {
        std::cout << tmp -> next -> coef;
    }
    if (tmp -> next -> index != 0) {
        if (tmp -> next -> index == 1) {
            std::cout << "x";
        }
        else {
            std::cout << "x^"
                      << tmp -> next -> index;
        }
    }
    tmp = tmp -> next;
    while (tmp -> next != tail) {
        if (tmp -> next -> coef == 1) {
            if (tmp -> next -> index == 0)
                std::cout << "+1";
            else
                std::cout << '+';
        }
        else if ((int)tmp -> next -> coef == -1) {
            std::cout << '-';
        }
        else {
            if (tmp -> next -> coef > 0) {
                std::cout << '+';
                if (tmp -> next -> index == 0 && tmp -> next -> coef == 1)
                    std::cout << '1';

            }
            std::cout << tmp -> next -> coef;
        }
        if (tmp -> next -> index != 0) {
            if (tmp -> next -> index == 1) {
                std::cout << "x";
            }
            else {
                std::cout << "x^"
                          << tmp -> next -> index;
            }
        }
        tmp = tmp -> next;
    }
    std::cout << std::endl;
}
