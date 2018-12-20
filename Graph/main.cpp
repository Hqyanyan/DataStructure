#include "MatrixGraph.h"   //�ڽӾ���
#include "LinkedGraph.h"   //�ڽӱ�


void menu();
bool judge(int, int, int, int wt = INFINITY);

int main() {
    //���ö�����Ϣ
    int a, n;
    std::cout << "ѡ��ͼ������----1.����ͼ 2.����ͼ" << std::endl;
    std::cin >> a;
    bool flag = a == 2;
    std::cout << "����ͼ�Ķ�������";
    std::cin >> a;
    n = a;
    //ͼ���ڽӾ������ڽӱ�
    MatrixGraph matrixGraph(a);
    LinkedGraph linkedGraph(a);
    //���ñ���Ϣ
    int vt1, vt2, wt;
    std::cout << "ÿ������һ������Ϣ����0 2 3��ʾ�Ӷ���0ָ�򶥵�2��һ����ȨΪ3������ߣ�����Ϊ0 0 0ʱ�������롣" << std::endl;
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
    //����ʵ��
    while (true) {
        menu();
        std::cin >> a;
        if (a == 0) {
            break;
        }
        switch (a) {
            case 1: {
                system("cls");
                std::cout << "ÿ������һ������Ϣ����0 2 3��ʾ�Ӷ���0ָ�򶥵�2��һ����ȨΪ3������ߣ�����Ϊ0 0 0ʱ�������롣" << std::endl;
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
                std::cout << "����Ҫɾ���ıߣ���0 2��ʾɾ�����Ӷ���0�붥��2�ıߣ�����Ϊ0 0ʱ��������" << std::endl;
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
                std::cout << "����Ҫ��ѯ�ıߣ���0 2��ʾ��ѯ����0�붥��2�Ƿ��б�����������Ϊ0 0ʱ��������" << std::endl;
                while (std::cin >> vt1 >> vt2) {
                    if (vt1 == 0 && vt2 == 0) {
                        break;
                    }
                    if (!judge(n, vt1, vt2)) {
                        continue;
                    }
                    if (matrixGraph.isEdge(vt1, vt2)) {
                        std::cout << "����" << vt1 << "�붥��" << vt2 << "֮���б�����" << std::endl;
                    }
                    else {
                        std::cout << "����" << vt1 << "�붥��" << vt2 << "֮��û�б�����" << std::endl;
                    }
                }
            }
                break;
            case 4: {
                system("cls");
                std::cout << "����Ҫ��ѯ�Ķ���,����Ϊ0ʱ��������" << std::endl;
                while (std::cin >> a) {
                    if (a == 0) {
                        break;
                    }
                    if (a < 0 || a > n) {
                        std::cout << "�Ƿ����룬����ķ�Χ��0-" << n - 1 << std::endl;
                        continue;
                    }
                    int count = 0;
                    for (int i = 0; i < matrixGraph.n(); i++) {
                        if (matrixGraph.isEdge(a, i)) {
                            count++;
                        }
                    }
                    std::cout << "�붥��" << a << "�����ı���" << count << "��" << std::endl;
                }
            }
                break;
            case 5: {
                system("cls");
                std::cout << "ѡ��һ����㣺";
                std::cin >> a;
                if (a < 0 || a > n) {
                    std::cout << "�Ƿ����룬����ķ�Χ��0-" << n - 1 << std::endl;
                    continue;
                }
                std::cout << "�ڽӾ���DFS��" << std::endl;
                matrixGraph.DFSTraverse(&matrixGraph, a);
                std::cout << "\n�ڽӱ�DFS��" << std::endl;
                linkedGraph.DFSTraverse(&linkedGraph, a);
            }
                break;
            case 6: {
                system("cls");
                std::cout << "ͼ���ڽӾ���" << std::endl;
                matrixGraph.printGraph();
                std::cout << "ͼ���ڽӱ�" << std::endl;
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
    std::cout << "========ѡ��Ҫִ�еĲ���========" << std::endl
              << "1.�����µı߻���ı�Ȩ" << std::endl
              << "2.ɾ����" << std::endl
              << "3.�ж��Ƿ�Ϊ��" << std::endl
              << "4.��ȡ�ߵ���Ŀ" << std::endl
              << "5.DFS" << std::endl
              << "6.���ͼ���ٽ������ڽӱ�" << std::endl
              << "0.�˳�" << std::endl
              << "=============================" << std::endl;
}

bool judge(int n, int vt1, int vt2, int wt) {
    if (vt1 >= n || vt2 >= n) {
        std::cout << "�Ƿ����룬����ķ�Χ��0-" << n - 1 << std::endl;
        return false;
    }
    if (vt1 == vt2) {
        std::cout << "�Ƿ����룬�������㲻�����" << std::endl;
        return false;
    }
    if (wt <= 0) {
        std::cout << "�Ƿ����룬��ȨӦ����0" << std::endl;
        return false;
    }
    return true;
}
