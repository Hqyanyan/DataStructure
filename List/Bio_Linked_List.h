//
// Created by i_still_mess_up on 2018/10/6.
//

#ifndef LIST_BIO_LINKED_LIST_H
#define LIST_BIO_LINKED_LIST_H

#include "Linked_List.h"
#include <iostream>


template <typename E>
struct Node {
    static Node<E>* freelist;
    E element;
    Node* prev;
    Node* next;

    Node(const E& it, Node* prevPtr, Node* nextPtr) {
        element = it;
        prev = prevPtr;
        next = nextPtr;
    }
    explicit Node(Node* prevPtr = NULL, Node* nextPtr = NULL) {
        prev = prevPtr;
        next = nextPtr;
    }

    void* operator new(size_t) {
        if (freelist == NULL) {
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
Node<E>* Node<E>::freelist = NULL;

template <typename E>
class Bio_Linked_List : public List<E> {
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
        while (head != NULL) {
            curr = head;
            head = head -> next;
            delete curr;
        }
    }

public:
    explicit Bio_Linked_List(int size = defaultSize);
    ~Bio_Linked_List();
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


#endif //LIST_BIO_LINKED_LIST_H
