//
// Created by i_still_mess_up on 2018/11/13.
//

#ifndef BST_NODE_H
#define BST_NODE_H

template <typename E>
class Node {
public:

    // Return the node's value
    virtual E& getElement() = 0;

    // Set the node's value
    virtual void setElement(const E&) = 0;

    // Return the node's left child
    virtual Node* left() const = 0;

    // Set the node's left child
    virtual void setLeft(Node*) = 0;

    // Return the node's right child
    virtual Node* right() const =  0;

    // Set the node's right child
    virtual void setRight(Node*) = 0;

    // Return true if the node is a leaf, false otherwise
    virtual bool isLeaf() = 0;
};



#endif //BST_NODE_H
