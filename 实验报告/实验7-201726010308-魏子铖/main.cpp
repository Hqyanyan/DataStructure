/*
���ļ��ж���һ�麺�ּ��ϣ�������֯���Ա��档����֯���Ա��ڲ�ѯʱ������ת�÷���������֯���Ա�����ݡ�
���ļ������ζ������ѯ�ĺ��֣��Ѳ�ѯ����������ļ��У����ҵ������رȽϵĴ��������û���ҵ������رȽϵĴ�����
 */


#include <fstream>
#include "SOArrayList.h"

int main() {
    SOArrayList test = SOArrayList(12);
    std::ifstream in;
    in.open("../test1.txt", std::ios::in);
    std::ofstream out;
    out.open("../respond1.txt", std::ios::out);
    std::string temp;
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
                        out << "���ҳɹ������Ҵ���Ϊ" << k / 2;
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


    test.print();
    in.close();
    return 0;
}