#include "BinTree.h"

int main() {
    BinTree t;
    std::cout << "先序输入一个二叉树，空子树用'/'代替，例如：abc//d//ef//g//" << std::endl;
    t.createBinTree();
    std::cout << "后序遍历： ";
    t.postOrder();
    std::cout << std::endl;

    std::cout << "树的高度： " << t.getHeight() << std::endl;
    std::cout << "结点个数： " << t.getCount() << std::endl;
    system("pause");
    return 0;
}
