//
// Created by i_still_mess_up on 2018/11/28.
//

#include "MatrixGraph.h"

void MatrixGraph::Init(int vt) {
    numVertex = vt;
    numEdge = 0;
    matrix = new int*[vt];
    for (int i = 0; i < vt; i++) {
        matrix[i] = new int[vt];
    }
    for (int i = 0; i < vt; i++) {
        for (int j = 0; j < vt; j++) {
            matrix[i][j] = 0;
        }
    }
    mark = new int[vt];
    for (int i = 0; i < vt; i++) {
        mark[i] = UNVISITED;
    }
}

MatrixGraph::MatrixGraph(int vt) {
    Init(vt);
}

MatrixGraph::~MatrixGraph() {
    delete [] mark;
    for (int i = 0; i < numVertex; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

int MatrixGraph::n() {
    return numVertex;
}

int MatrixGraph::getFirst(int vt) {
    for (int i = 0; i < numVertex; i++) {
        if (matrix[vt][i] != 0) {
            return i;
        }
    }
    return numVertex;
}

int MatrixGraph::next(int vt1, int vt2) {
    for (int i = vt2 + 1; i < numVertex; i++) {
        if (matrix[vt1][i] != 0) {
            return i;
        }
    }
    return numVertex + 1;
}

void MatrixGraph::setEdge(int vt1, int vt2, int wt) {
    try {
        if (wt <= 0) {
            throw "Illegal weight value";
        }
        if (matrix[vt1][vt2] == 0) {
            numEdge++;
        }
        matrix[vt1][vt2] = wt;
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

int MatrixGraph::getMark(int vt) {
    return mark[vt];
}

void MatrixGraph::setMark(int vt, int value) {
    mark[vt] = value;
}

