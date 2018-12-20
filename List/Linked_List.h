//
// Created by i_still_mess_up on 2018/10/5.
//

#ifndef LIST_LINKED_LIST_H
#define LIST_LINKED_LIST_H

#include "List.h"
#include <iostream>

template <typename E>
struct Node {
    static Node<E>* freelist;
    E element;
    Node* next;

    explicit Node(const E& element_value, Node* nextPtr = nullptr) {
        element = element_value;
        next = nextPtr;
    }
    explicit Node(Node* nextPtr = nullptr) {
        next = nextPtr;
    }

    void* operator new(size_t) {
        if (freelist == nullptr) {
            return ::new Node;
        }
        Node<E>* tmp = freelist;
        freelist = freelist -> next;
        return tmp;
    }
    void operator delete(void* ptr) {
        ((Node<E>*) ptr) -> next = freelist;
        freelist = (Node<E>*) ptr;
    }
};

template <typename E>
Node<E>* Node<E>::freelist = nullptr;

template <typename E>
class Linked_List : public List<E>{
private:
    Node<E>* head;
    Node<E>* curr;
    Node<E>* tail;
    int cnt; //length of list

    void init() {
        curr = tail = head = new Node<E>;
        cnt = 0;
    }
    void removeAll() {
        while (head != nullptr) {
            curr = head;
            head = head -> next;
            delete curr;
        }
    }

public:
    Linked_List();
    ~Linked_List();
    void print() const;
    void clear();
    void insert(const E&);
    void append(const E&);
    E remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length() const;
    int currPosition() const;
    void moveToPosition(int);
    const E& getValue() const;
};


#endif //LIST_LINKED_LIST_H
