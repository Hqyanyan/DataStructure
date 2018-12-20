//
// Created by i_still_mess_up on 2018/10/2.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

static int defaultSize = 1001;

template <typename E>
class List {
private:
    void operator =(const List&) {}
    List(const List&) = default;

public:
    List() = default;
    virtual ~List() = default;

    virtual void clear() = 0;
    virtual void insert(const E&) = 0;
    virtual void append(const E&) = 0;
    virtual E remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() const = 0;
    virtual int currPosition() const = 0;
    virtual void moveToPosition(int) = 0;
    virtual const E& getValue() const = 0;
};


#endif //LIST_LIST_H
