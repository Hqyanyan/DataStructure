//
// Created by i_still_mess_up on 2018/10/24.
//

#ifndef QUEUE_ARRAY_QUEUE_H
#define QUEUE_ARRAY_QUEUE_H

#include "Queue.h"

template <typename E>
class Array_Queue : public Queue<E>{
private:
    int maxSize;
    int front;
    int rear;
    E* listArray;

public:
    explicit Array_Queue(int size = 1001);
    ~Array_Queue();
    void clear();
    void enqueue(const E&);
    E dequeue();
    const E& frontValue() const;
    int length() const;
};


#endif //QUEUE_ARRAY_QUEUE_H
