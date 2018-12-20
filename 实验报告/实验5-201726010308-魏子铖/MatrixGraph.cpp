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

int MatrixGraph::e() {
    return numEdge;
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
    return numVertex;
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

void MatrixGraph::deleteEdge(int vt1, int vt2) {
    if (matrix[vt1][vt2] != 0) {
        numEdge--;
    }
    matrix[vt1][vt2] = 0;
}

bool MatrixGraph::isEdge(int vt1, int vt2) {
    return matrix[vt1][vt2] != 0;
}

int MatrixGraph::getWeight(int vt1, int vt2) {
    return matrix[vt1][vt2];
}

int MatrixGraph::getMark(int vt) {
    return mark[vt];
}

void MatrixGraph::setMark(int vt, int value) {
    mark[vt] = value;
}

void MatrixGraph::printGraph() {
    std::cout << "\t|\t";
    for (int i = 0; i < numVertex; i++) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
    for (int i = 0; i < numVertex + 2; i++) {
        std::cout << "！！！！！！！！";
    }
    std::cout << std::endl;
    for (int i = 0; i < numVertex; i++) {
        std::cout << i << "\t|\t";
        for (int j = 0; j < numVertex; j++) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void MatrixGraph::DFSTraverse(MatrixGraph* m, int vt) {
    std::cout << vt << ' ';
    m->setMark(vt, VISITED);
    for (int w = m->getFirst(vt); w < m->numVertex; w = m->next(vt, w)) {
        if (m->getMark(w) == UNVISITED) {
            DFSTraverse(m, w);
        }
    }
}
