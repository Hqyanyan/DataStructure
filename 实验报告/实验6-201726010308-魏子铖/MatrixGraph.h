//
// Created by istil on 2018/12/9.
//

#ifndef CCFEXERCISE_MATRIXGRAPH_H
#define CCFEXERCISE_MATRIXGRAPH_H
#define VISITED 1
#define UNVISITED -1

#include <iostream>

class MatrixGraph {
private:
    int numVertex;
    int numEdge;
    int** matrix;
    int* mark;

    void Init(int) ;

public:
    explicit MatrixGraph(int);
    ~MatrixGraph();

    int n() ;
    int getFirst(int) ;
    int next(int, int) ;
    void setEdge(int, int, int) ;
    int getMark(int) ;
    void setMark(int, int) ;
};

#endif //CCFEXERCISE_MATRIXGRAPH_H
