//
// Created by i_still_mess_up on 2018/10/23.
//
#include "Poly.h"

int main() {
    double coef = 0.0;
    int index = 0;
    Poly A, B, C;
    std::cout << "ÿ�������������֣���һ����ʾ�ݴΣ��ڶ�����ʾ���ݴε�ϵ�����Կո����\n"
                 "��0 0����һ������ʽ������\n"
              << "===�������ʽA(x)==="
              << std::endl;
    while (std::cin >> index >> coef) {
        if ((int)coef == 0 && index == 0) {
            break;
        }
        A.insert(coef, index);
    }
    std::cout << "===�������ʽB(x)==="
              << std::endl;
    while (std::cin >> index >> coef) {
        if ((int)coef == 0 && index == 0) {
            break;
        }
        B.insert(coef, index);
    }

    while (A.hasNext() || B.hasNext()) {
        if (A.hasNext() && B.hasNext()) {
            int indexA = A.getIndex();
            int indexB = B.getIndex();
            if (indexA == indexB) {
                double coefA = A.getCoef();
                double coefB = B.getCoef();
                coef = coefA + coefB;
                if ((int)coef != 0)
                    C.insert(coef, indexA);
                A.next();
                B.next();
            }
            else if (indexA > indexB) {
                coef = A.getCoef();
                C.insert(coef, indexA);
                A.next();
            }
            else {
                coef = B.getCoef();
                C.insert(coef, indexB);
                B.next();
            }
        }
        else if (A.hasNext()) {
            int indexA = A.getIndex();
            coef = A.getCoef();
            C.insert(coef, indexA);
            A.next();
        }
        else {
            int indexB = B.getIndex();
            coef = B.getCoef();
            C.insert(coef, indexB);
            B.next();
        }
    }
    A.clear();
    B.clear();
    C.print();
    system("pause"); 
    return 0;
}
