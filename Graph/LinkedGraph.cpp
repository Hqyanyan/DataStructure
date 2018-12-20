//
// Created by i_still_mess_up on 2018/11/28.
//

#include "LinkedGraph.h"

Edge::Edge() {
    vertex = wt = -1;
}

Edge::Edge(int vt, int wt) {
    vertex = vt;
    this->wt = wt;
}

bool comp(const Edge& v1, const Edge& v2) {
    return v1.vertex < v2.vertex;
}

void LinkedGraph::Init(int vt) {
    numVertex = vt;
    numEdge = 0;
    AdjVertex = new Vertex[vt];
    for (int i = 0; i < vt; i++) {
        AdjVertex[i].edge = new std::vector<Edge>();
        AdjVertex[i].vertex = i;
    }
    mark = new int[vt];
    for (int i = 0; i < vt; i++) {
        mark[i] = UNVISITED;
    }
}

LinkedGraph::LinkedGraph(int vt) {
    Init(vt);
}

LinkedGraph::~LinkedGraph() {
    delete [] mark;
    for (int i = 0; i < numVertex; i++) {
        delete AdjVertex[i].edge;
    }
    delete [] AdjVertex;
}

int LinkedGraph::n() {
    return numVertex;
}

int LinkedGraph::e() {
    return numEdge;
}

int LinkedGraph::getFirst(int vt) {
    if (!AdjVertex[vt].edge->empty()) {
        return AdjVertex[vt].edge->front().vertex == INFINITY ? n() : AdjVertex[vt].edge->front().vertex;
    }
    else {
        return n();
    }
}

int LinkedGraph::next(int vt1, int vt2) {
    for (int i = vt2 + 1; i < numVertex; i++) {
        if (isEdge(vt1, i)) {
            return i;
        }
    }
    return numVertex;
}

void LinkedGraph::setEdge(int vt1, int vt2, int wt) {
    try {
        if (wt <= 0) {
            throw "Illegal weight value";
        }
        Edge tmp(vt2, wt);

        if (isEdge(vt1, vt2)) {
            int idx = findIndex(vt1, vt2);
            std::cout << idx << std::endl;
            AdjVertex[vt1].edge->at(static_cast<unsigned int>(idx)).wt = wt;
        }
        else {
            numEdge++;
            AdjVertex[vt1].edge->push_back(tmp);
            std::sort(AdjVertex[vt1].edge->begin(), AdjVertex[vt1].edge->end(), comp);
        }
    }
    catch (const char* str) {
        std::cerr << str << std::endl;
    }
}

void LinkedGraph::deleteEdge(int vt1, int vt2) {
    if (isEdge(vt1, vt2)) {
        std::vector<Edge>::iterator it;
        for (it = AdjVertex[vt1].edge->begin(); it != AdjVertex[vt1].edge->end(); it++) {
            if (it.base()->vertex == vt2) {
                break;
            }
        }
        AdjVertex[vt1].edge->erase(it);
    }
}

bool LinkedGraph::isEdge(int vt1, int vt2) {
    return findIndex(vt1, vt2) != n();
}

int LinkedGraph::getWeight(int vt1, int vt2) {
    return isEdge(vt1, vt2)
                ? AdjVertex[vt1].edge->at(static_cast<unsigned int>(findIndex(vt1, vt2))).wt
                : 0;
}

int LinkedGraph::getMark(int vt) {
    return mark[vt];
}

void LinkedGraph::setMark(int vt, int value) {
    mark[vt] = value;
}

int LinkedGraph::findIndex(int vt1, int vt2) {
    int i = 0;
    int j = AdjVertex[vt1].edge->size();
    while (i < j) {
        if (AdjVertex[vt1].edge->at(static_cast<unsigned int>(i)).vertex == vt2) {
            return i;
        }
        i++;
    }
    return n();
}

void LinkedGraph::printGraph() {
    for (int i = 0; i < numVertex; i++) {
        std::cout << AdjVertex[i].vertex << "-->";
        std::vector<Edge>::iterator it;
        for (it = AdjVertex[i].edge->begin(); it != AdjVertex[i].edge->end(); it++) {
            if (it.base()->vertex != INFINITY) {
                std::cout << it.base()->vertex << '(' << it.base()->wt << ')' << "-->";
            }
        }
        std::cout << "NULL" << std::endl;
    }
}

void LinkedGraph::DFSTraverse(LinkedGraph* m, int vt) {
    std::cout << vt << ' ';
    m->setMark(vt, VISITED);
    for (int w = m->getFirst(vt); w < m->n(); w = m->next(vt, w)) {
        if (m->getMark(w) == UNVISITED) {
            DFSTraverse(m, w);
        }
    }
}


