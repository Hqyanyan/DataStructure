
#include "BST.h"

int main() {
    std::cout << "Welcome!\n"
              << "����Ҫ�����ľ�̬���ұ�Ԫ�ظ�����";
    int count = 0;

    while (std::cin >> count) {
        if (count > 0) {
            break;
        }
        std::cout << "������Ч�����������룺";
    }

    std::cout << "���������е�Ԫ��(����)���Կո���" << std::endl;
    BST StaticSearchTable;
    for (int i = 0; i < count; i++) {
        int key;
        std::cin >> key;
        StaticSearchTable.insert(key);
    }

    int key = 0;
    while (true) {
        std::cout << "����һ��Ҫ���ҵ�Ԫ�أ�����-1�������ң�";
        std::cin >> key;
        if (key == -1) {
            break;
        }
        int ans = StaticSearchTable.find(key);
        if (ans > 0) {
            std::cout << "���ҳɹ������Ҵ���Ϊ" << ans << std::endl;
        }
        else {
            std::cout << "����ʧ�ܣ����Ҵ���Ϊ" << -ans << std::endl;
        }
    }
    system("pause");
    return 0;
}