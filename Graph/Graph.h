//
// Created by i_still_mess_up on 2018/11/28.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#define UNVISITED -1
#define VISITED 1
#define INFINITY 2147483647

#include <iostream>

class Graph {
public:
    Graph() = default;
    ~Graph() = default;

    virtual void Init(int) = 0;
    virtual int n() = 0;
    virtual int e() = 0;
    virtual int getFirst(int) = 0;
    virtual int next(int, int) = 0;
    virtual void setEdge(int, int, int) = 0;
    virtual void deleteEdge(int, int) = 0;
    virtual bool isEdge(int, int) = 0;
    virtual int getWeight(int, int) = 0;
    virtual int getMark(int) = 0;
    virtual void setMark(int, int) = 0;
    virtual void printGraph() = 0;
};


#endif //GRAPH_GRAPH_H
