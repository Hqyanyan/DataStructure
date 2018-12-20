//
// Created by i_still_mess_up on 2018/10/5.
//
#include "Linked_List.h"

template <typename E>
Linked_List<E>::Linked_List() {
    init();
}

template <typename E>
Linked_List<E>::~Linked_List(){
    removeAll();
}

template <typename E>
void Linked_List<E>::print() const {
    Node<E>* tmp = head -> next;
    std::cout << '[';
    while (tmp != tail) {
        std::cout << tmp -> element << ", ";
        tmp = tmp -> next;
    }
    std::cout << tmp -> element << ']' << std::endl;
}

template <typename E>
void Linked_List<E>::clear() {
    removeAll();
    init();
}

template <typename E>
void Linked_List<E>::insert(const E& it) {
    curr -> next = new Node<E>(it, curr -> next);
    if (tail == curr) {
        tail = curr -> next;
    }
    cnt++;
}

template <typename E>
void Linked_List<E>::append(const E& it) {
    tail = tail -> next = new Node<E>(it);
    cnt++;
}

template <typename E>
E Linked_List<E>::remove() {
    try {
        if (curr -> next == nullptr) {
            throw "No element";
        }
        E it = curr -> next -> element;
        Node<E>* tmp = curr -> next;
        if (curr -> next == tail) {
            tail = curr;
        }
        curr -> next = curr -> next -> next;
        delete tmp;
        cnt--;
        return it;
    }
    catch(const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
void Linked_List<E>::moveToStart() {
    curr = head;
}

template <typename E>
void Linked_List<E>::moveToEnd() {
    curr = tail;
}

template <typename E>
void Linked_List<E>::prev() {
    try {
        if (curr == head) {
            throw "No previous element";
        }
        Node<E>* tmp = head;
        while (tmp -> next != curr) {
            tmp = tmp -> next;
        }
        curr = tmp;
    }
    catch(const char* str) {
        std::cerr << str << std::endl;
    }

}

template <typename E>
void Linked_List<E>::next() {
    try {
        if (curr == tail) {
            throw "No next element";
        }
        curr = curr -> next;
    }
    catch(const char* str) {
        std::cerr << str << std::endl;
    }

}

template <typename E>
int Linked_List<E>::length() const {
    return cnt;
}

template <typename E>
int Linked_List<E>::currPosition() const {
    int it = 0;
    Node<E>* tmp = head;
    while (tmp != curr) {
        it++;
        tmp = tmp -> next;
    }
    return it;
}

template <typename E>
void Linked_List<E>::moveToPosition(int position) {
    try {
        if (position < 0 || position > cnt) {
            throw "Position out of range";
        }
        this -> moveToStart();
        while (position--) {
            curr = curr -> next;
        }
    }
    catch(const char* str) {
        std::cerr << str << std::endl;
    }
}

template <typename E>
const E& Linked_List<E>::getValue() const {
    try {
        if (curr -> next == nullptr) {
            throw "No value";
        }
        return curr -> next -> element;
    }
    catch(const char* str) {
        std::cerr << str << std::endl;
    }
}