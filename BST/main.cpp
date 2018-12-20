// Static Search Table

#include <iostream>
#include "BSTNode.cpp"
#include "BST.cpp"

int main() {
    BST<int, char> a;
    a.insert(5, 'a');
    a.insert(7, 'a');
    a.insert(6, 'a');
    a.insert(2, 'a');
    a.insert(3, 'a');
    a.insert(4, 'a');
    int p = a.remove(5);
    a.print();
    return 0;
}