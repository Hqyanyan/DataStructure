#include "MatrixGraph.h"   //邻接矩阵
#include "LinkedGraph.h"   //邻接表


void menu();
bool judge(int, int, int, int wt = INFINITY);

int main() {
    //设置顶点信息
    int a, n;
    std::cout << "选择图的类型----1.有向图 2.无向图" << std::endl;
    std::cin >> a;
    bool flag = a == 2;
    std::cout << "输入图的顶点数：";
    std::cin >> a;
    n = a;
    //图的邻接矩阵与邻接表
    MatrixGraph matrixGraph(a);
    LinkedGraph linkedGraph(a);
    //设置边信息
    int vt1, vt2, wt;
    std::cout << "每行输入一个边信息，如0 2 3表示从顶点0指向顶点2的一条边权为3的有向边，输入为0 0 0时结束输入。" << std::endl;
    while (std::cin >> vt1 >> vt2 >> wt) {
        if (vt1 == 0 && vt2 == 0) {
            break;
        }
        if (!judge(n, vt1, vt2, wt)) {
            continue;
        }
        matrixGraph.setEdge(vt1, vt2, wt);
        linkedGraph.setEdge(vt1, vt2, wt);
        if (flag) {
            matrixGraph.setEdge(vt2, vt1, wt);
            linkedGraph.setEdge(vt2, vt1, wt);
        }
    }
    //操作实现
    while (true) {
        menu();
        std::cin >> a;
        if (a == 0) {
            break;
        }
        switch (a) {
            case 1: {
                system("cls");
                std::cout << "每行输入一个边信息，如0 2 3表示从顶点0指向顶点2的一条边权为3的有向边，输入为0 0 0时结束输入。" << std::endl;
                while (std::cin >> vt1 >> vt2 >> wt) {
                    if (vt1 == 0 && vt2 == 0) {
                        break;
                    }
                    if (!judge(n, vt1, vt2, wt)) {
                        continue;
                    }
                    matrixGraph.setEdge(vt1, vt2, wt);
                    linkedGraph.setEdge(vt1, vt2, wt);
                    if (flag) {
                        matrixGraph.setEdge(vt2, vt1, wt);
                        linkedGraph.setEdge(vt2, vt1, wt);
                    }
                }
            }
                break;
            case 2: {
                system("cls");
                std::cout << "输入要删除的边，如0 2表示删除连接顶点0与顶点2的边，输入为0 0时结束输入" << std::endl;
                while (std::cin >> vt1 >> vt2) {
                    if (vt1 == 0 && vt2 == 0) {
                        break;
                    }
                    if (!judge(n, vt1, vt2)) {
                        continue;
                    }
                    matrixGraph.deleteEdge(vt1, vt2);
                    linkedGraph.deleteEdge(vt1, vt2);
                    if (flag) {
                        matrixGraph.deleteEdge(vt1, vt2);
                        linkedGraph.deleteEdge(vt1, vt2);
                    }
                }
            }
                break;
            case 3: {
                system("cls");
                std::cout << "输入要查询的边，如0 2表示查询顶点0与顶点2是否有边相连，输入为0 0时结束输入" << std::endl;
                while (std::cin >> vt1 >> vt2) {
                    if (vt1 == 0 && vt2 == 0) {
                        break;
                    }
                    if (!judge(n, vt1, vt2)) {
                        continue;
                    }
                    if (matrixGraph.isEdge(vt1, vt2)) {
                        std::cout << "顶点" << vt1 << "与顶点" << vt2 << "之间有边相连" << std::endl;
                    }
                    else {
                        std::cout << "顶点" << vt1 << "与顶点" << vt2 << "之间没有边相连" << std::endl;
                    }
                }
            }
                break;
            case 4: {
                system("cls");
                std::cout << "输入要查询的顶点,输入为0时结束输入" << std::endl;
                while (std::cin >> a) {
                    if (a == 0) {
                        break;
                    }
                    if (a < 0 || a > n) {
                        std::cout << "非法输入，顶点的范围是0-" << n - 1 << std::endl;
                        continue;
                    }
                    int count = 0;
                    for (int i = 0; i < matrixGraph.n(); i++) {
                        if (matrixGraph.isEdge(a, i)) {
                            count++;
                        }
                    }
                    std::cout << "与顶点" << a << "相连的边有" << count << "条" << std::endl;
                }
            }
                break;
            case 5: {
                system("cls");
                std::cout << "选择一个起点：";
                std::cin >> a;
                if (a < 0 || a > n) {
                    std::cout << "非法输入，顶点的范围是0-" << n - 1 << std::endl;
                    continue;
                }
                std::cout << "邻接矩阵DFS：" << std::endl;
                matrixGraph.DFSTraverse(&matrixGraph, a);
                std::cout << "\n邻接表DFS：" << std::endl;
                linkedGraph.DFSTraverse(&linkedGraph, a);
            }
                break;
            case 6: {
                system("cls");
                std::cout << "图的邻接矩阵：" << std::endl;
                matrixGraph.printGraph();
                std::cout << "图的邻接表：" << std::endl;
                linkedGraph.printGraph();
            }
                break;
            default:
                break;
        }
        system("pause");
    }

    return 0;
}

void menu() {
    std::cout << "========选择要执行的操作========" << std::endl
              << "1.设置新的边或更改边权" << std::endl
              << "2.删除边" << std::endl
              << "3.判断是否为边" << std::endl
              << "4.获取边的数目" << std::endl
              << "5.DFS" << std::endl
              << "6.输出图的临界矩阵和邻接表" << std::endl
              << "0.退出" << std::endl
              << "=============================" << std::endl;
}

bool judge(int n, int vt1, int vt2, int wt) {
    if (vt1 >= n || vt2 >= n) {
        std::cout << "非法输入，顶点的范围是0-" << n - 1 << std::endl;
        return false;
    }
    if (vt1 == vt2) {
        std::cout << "非法输入，两个顶点不能相等" << std::endl;
        return false;
    }
    if (wt <= 0) {
        std::cout << "非法输入，边权应大于0" << std::endl;
        return false;
    }
    return true;
}
