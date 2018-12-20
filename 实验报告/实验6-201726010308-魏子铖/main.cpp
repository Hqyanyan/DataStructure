#include "MatrixGraph.h"

int visit[1001][1001];
void DFSTraverse(MatrixGraph* m, int vt) {
    m->setMark(vt, VISITED);
    for (int w = m->getFirst(vt); w <= m->n(); w = m->next(vt, w)) {
        if (m->getMark(w) == UNVISITED) {
            DFSTraverse(m, w);
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    MatrixGraph Internet(N);
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            visit[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int vt1, vt2;
        std::cin >> vt1 >> vt2;
        Internet.setEdge(vt1 - 1, vt2 - 1, 1);
    }
    for (int i = 0; i < N; i++) {
        DFSTraverse(&Internet, i);
        for (int j = 0; j < N; j++) {
            if (Internet.getMark(j) != UNVISITED) {
                visit[i][j] = 1;
                visit[j][i] = 1;
                Internet.setMark(j, UNVISITED);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] == 0) {
                break;
            }
            if (j == N - 1) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    system("pause"); 
}
