#include "BinTree.h"

int main() {
    BinTree t;
    std::cout << "��������һ������������������'/'���棬���磺abc//d//ef//g//" << std::endl;
    t.createBinTree();
    std::cout << "��������� ";
    t.postOrder();
    std::cout << std::endl;

    std::cout << "���ĸ߶ȣ� " << t.getHeight() << std::endl;
    std::cout << "�������� " << t.getCount() << std::endl;
    system("pause");
    return 0;
}
