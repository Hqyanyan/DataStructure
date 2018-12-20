//
// Created by i_still_mess_up on 2018/11/28.
//

#ifndef GRAPH_LINKEDGRAPH_H
#define GRAPH_LINKEDGRAPH_H

#include "Graph.h"
#include <vector>
#include <algorithm>

struct Edge {
    int vertex;
    int wt;

    Edge();
    Edge(int, int);
};

struct Vertex {
    int vertex;
    std::vector<Edge>* edge;
};


class LinkedGraph : public Graph {
private:
    Vertex* AdjVertex;
    int numVertex;
    int numEdge;
    int* mark;

    void Init(int) override;
    int findIndex(int, int);
    friend bool comp(const Edge&, const Edge&);

public:
    explicit LinkedGraph(int);
    ~LinkedGraph();

    int n() override;
    int e() override;

    int getFirst(int) override;
    int next(int, int) override;
    void setEdge(int, int, int) override;
    void deleteEdge(int, int) override;
    bool isEdge(int, int) override;
    int getWeight(int, int) override;
    int getMark(int) override;
    void setMark(int, int) override;
    void printGraph() override;
    void DFSTraverse(LinkedGraph*, int);
};


#endif //GRAPH_LINKEDGRAPH_H
