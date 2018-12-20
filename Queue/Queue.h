//
// Created by i_still_mess_up on 2018/10/24.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

template <typename E>
class Queue {
private:
    void operator =(const Queue&) {}
    Queue(const Queue&) = default;

public:
    Queue() = default;
    virtual ~Queue() = default;

    virtual void clear() = 0;
    virtual void enqueue(const E&) = 0;
    virtual E dequeue() = 0;
    virtual const E& frontValue() const = 0;
    virtual int length() const = 0;
};


#endif //QUEUE_QUEUE_H
