//
// Created by i_still_mess_up on 2018/11/28.
//

#ifndef GRAPH_MATRIXGRAPH_H
#define GRAPH_MATRIXGRAPH_H

#include "Graph.h"

class MatrixGraph : public Graph {
private:
    int numVertex;
    int numEdge;
    int** matrix;
    int* mark;

    void Init(int) override;

public:
    explicit MatrixGraph(int);
    ~MatrixGraph();

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
    void DFSTraverse(MatrixGraph*, int);
};

#endif //GRAPH_MATRIXGRAPH_H
