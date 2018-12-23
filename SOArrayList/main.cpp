/*
从文件中读入一组汉字集合，用自组织线性表保存。自组织线性表在查询时，采用转置法调整自组织线性表的内容。
从文件中依次读入需查询的汉字，把查询结果保存在文件中（如找到，返回比较的次数，如果没有找到，返回比较的次数）
*/

#include <fstream>
#include "SOArrayList.h"

int main() {
    std::string fileIn[5] = {
            "../test1.txt",
            "../test2.txt",
            "../test3.txt",
            "../test4.txt",
            "../test5.txt"
    };
    std::string fileOut[5] = {
            "../respond1.txt",
            "../respond2.txt",
            "../respond3.txt",
            "../respond4.txt",
            "../respond5.txt"
    };

    std::string temp;
    for (int s = 0; s < 5; s++) {
        std::ifstream in;
        std::ofstream out;
        SOArrayList test = SOArrayList(12);
        in.open(fileIn[s], std::ios::in);
        out.open(fileOut[s], std::ios::out);
        if (in.is_open()) {
            int count = 1;
            while (!in.eof()) {
                in >> temp;
                std::cout << temp << std::endl;
                for (int i = 0; i < temp.length(); i += 2) {
                    if (count) {
                        test.append(temp[i], temp[i + 1]);
                    }
                    else {
                        int k = test.find(temp[i], temp[i + 1]);
                        if (k != 12) {
                            out << "查找成功，查找次数为" << k / 2 + 1;
                        }
                        else {
                            out << "查找失败，查找次数为" << k / 2;
                        }
                        out << std::endl;
                    }
                }
                count = 0;
            }
        }
        test.print();
        in.close();  //一定要记得关闭文件
        out.close();
    }
    return 0;
}
