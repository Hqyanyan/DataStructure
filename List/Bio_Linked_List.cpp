//
// Created by i_still_mess_up on 2018/10/6.
//

#include "Bio_Linked_List.h"
#include "Linked_List.h"

template <typename E>
Bio_Linked_List<E>::Bio_Linked_List(int size) {
    init();
}

template <typename E>
Bio_Linked_List<E>::~Bio_Linked_List() {
    removeAll();
}

template <typename E>
void Bio_Linked_List<E>::print() const {
    Node<E>* tmp = head -> next;
    std::cout << '[';
    while (tmp != tail) {
        std::cout << tmp -> element << ", ";
        tmp = tmp -> next;
    }
    std::cout << tmp -> element << ']' << std::endl;
}

template <typename E>
void Bio_Linked_List<E>::clear() {
    removeAll();
    init();
}

template <typename E>
void Bio_Linked_List<E>::insert(const E& it) {
    ;
}

template <typename E>
void Bio_Linked_List<E>::append(const E& it) {
    ;
}

template <typename E>
E Bio_Linked_List<E>::remove() {
    ;
}

template <typename E>
void Bio_Linked_List<E>::moveToStart() {
    ;
}

template <typename E>
void Bio_Linked_List<E>::moveToEnd() {
    ;
}

template <typename E>
void Bio_Linked_List<E>::prev() {
    ;
}

template <typename E>
void Bio_Linked_List<E>::next() {
    ;
}

template <typename E>
int Bio_Linked_List<E>::length() const {
    ;
}

template <typename E>
int Bio_Linked_List<E>::currPosition() const {
    ;
}

template <typename E>
void Bio_Linked_List<E>::moveToPosition(int position) {
    ;
}

template <typename E>
const E& Bio_Linked_List<E>::getValue() const {
    ;
}