
#include "BST.h"

int main() {
    std::cout << "Welcome!\n"
              << "输入要创建的静态查找表元素个数：";
    int count = 0;

    while (std::cin >> count) {
        if (count > 0) {
            break;
        }
        std::cout << "输入无效！请重新输入：";
    }

    std::cout << "输入插入表中的元素(整数)，以空格间隔" << std::endl;
    BST StaticSearchTable;
    for (int i = 0; i < count; i++) {
        int key;
        std::cin >> key;
        StaticSearchTable.insert(key);
    }

    int key = 0;
    while (true) {
        std::cout << "输入一个要查找的元素，输入-1结束查找：";
        std::cin >> key;
        if (key == -1) {
            break;
        }
        int ans = StaticSearchTable.find(key);
        if (ans > 0) {
            std::cout << "查找成功，查找次数为" << ans << std::endl;
        }
        else {
            std::cout << "查找失败，查找次数为" << -ans << std::endl;
        }
    }
    system("pause");
    return 0;
}