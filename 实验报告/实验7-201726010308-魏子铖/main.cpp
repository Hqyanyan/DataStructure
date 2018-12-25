/*
���ļ��ж���һ�麺�ּ��ϣ�������֯���Ա��档����֯���Ա��ڲ�ѯʱ������ת�÷���������֯���Ա�����ݡ�
���ļ������ζ������ѯ�ĺ��֣��Ѳ�ѯ����������ļ��У����ҵ������رȽϵĴ��������û���ҵ������رȽϵĴ�����
*/

#include <fstream>
#include "SOArrayList.h"

int main() {
    const char* fileIn[5] = {
            "test1.txt",
            "test2.txt",
            "test3.txt",
            "test4.txt",
            "test5.txt"
    };
    const char* fileOut[5] = {
            "respond1.txt",
            "respond2.txt",
            "respond3.txt",
            "respond4.txt",
            "respond5.txt"
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
                // std::cout << temp << std::endl;
                for (int i = 0; i < temp.length(); i += 2) {
                    if (count) {
                        test.append(temp[i], temp[i + 1]);
                    }
                    else {
                        int k = test.find(temp[i], temp[i + 1]);
                        if (k != 12) {
                            out << "���ҳɹ������Ҵ���Ϊ" << k / 2 + 1;
                        }
                        else {
                            out << "����ʧ�ܣ����Ҵ���Ϊ" << k / 2;
                        }
                        out << std::endl;
                    }
                }
                count = 0;
            }
        }
        std::cout << std::endl << "test" << s + 1 << ".txt������ѯ�����Ա��е�ֵΪ��" << std::endl;
        test.print();
        in.close();  //һ��Ҫ�ǵùر��ļ�
        out.close();
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}
