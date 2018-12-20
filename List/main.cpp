/*
��������֧��C++11��׼��������뱨���� 
*/ 
#include "Array_List.cpp"
#include "Linked_List.cpp"
using namespace std;

void menuStart();
void menuFunction();
template <typename T>
void test();
int game();

int main() {
    int tmp = 0;
    while (true) {
        menuStart();
        cin >> tmp;
        switch (tmp) {
            case 1:
                test<int>();
                break;
            case 2:
                test<char>();
                break;
            case 3:
                test<double>();
                break;
            case 4:
                test<bool>();
                break;
            case 5:
                test<string>();
                break;
            case 6:
                cout << "��" << game() << "λС���ѻ�ʤ!" << endl;
                break;
            case 0:
                return 0;
            default:
                cout << "δ�����������������룡" << endl;
                break;
        }
    }
}
void menuStart() {
    cout << "===============ѡ��Ҫ���Ե����ݼ�===============" << endl;
    cout << "===============1.Integer====================" << endl;
    cout << "===============2.Character==================" << endl;
    cout << "===============3.Double=====================" << endl;
    cout << "===============4.Bool=======================" << endl;
    cout << "===============5.String=====================" << endl;
    cout << "===============6.������Ľ��=================" << endl;
    cout << "===============0.�˳�����=====================" << endl;
}

void menuFunction() {
    cout << "===============ѡ��Ҫ���ԵĹ���=================" << endl;
    cout << "| 1.����Ԫ��(�½������Ա��������Ԫ��)" << endl;
    cout << "| 2.�ڵ�ǰλ�ò���Ԫ��" << endl;
    cout << "| 3.�Ƴ���ǰλ��Ԫ��" << endl;
    cout << "| 4.�ƶ�����ʼλ��" << endl;
    cout << "| 5.�ƶ�������λ��" << endl;
    cout << "| 6.�ƶ���ǰһλ��" << endl;
    cout << "| 7.�ƶ�����һλ��" << endl;
    cout << "| 8.�������Ա�ĳ���" << endl;
    cout << "| 9.���ص�ǰλ��" << endl;
    cout << "| 10.�ƶ���ָ��λ��" << endl;
    cout << "| 11.���ص�ǰλ��Ԫ��ֵ" << endl;
    cout << "| 0.���Խ������˳�����" << endl;
    cout << "=============================================" << endl;
}

template <typename T>
void test() {
    system("cls");
    int size = 0, tmp = 0;
    cout << "����������ݵĹ�ģ����'15': ";
    cin >> size;
    Array_List<T> test1(size);
    Linked_List<T> test2;
    while (true) {
        menuFunction();
        cin >> tmp;
        switch (tmp) {
            case 1: {
                cout << "����Ҫ���Ԫ�صĸ���: ";
                int size1;
                cin >> size1;
                cout << "����Ҫ��ӵ�Ԫ�أ��ÿո�ֿ�: ";
                for (int i = 0; i < size1; i++) {
                    T temp;
                    cin >> temp;
                    test1.append(temp);
                    test2.append(temp);
                }
                cout << "��Ӻ�����Ա�Ϊ: " << endl;
                cout << "˳���: ";
                test1.print();
                cout << "����: ";
                test2.print();
            }
                break;
            case 2: {
                cout << "����Ҫ�����Ԫ��: ";
                T temp;
                cin >> temp;
                test1.insert(temp);
                test2.insert(temp);
                cout << "���������Ա�Ϊ: " << endl;
                cout << "˳���: ";
                test1.print();
                cout << "����: ";
                test2.print();
            }
                break;
            case 3: {
                test1.remove();
                test2.remove();
                cout << "�Ƴ���ǰλ��Ԫ�غ�����Ա�Ϊ: " << endl;
                cout << "˳���: ";
                test1.print();
                cout << "����: ";
                test2.print();
            }
                break;
            case 4: {
                test1.moveToStart();
                test2.moveToStart();
                cout << "�ƶ���ǰλ��Ϊ: " << test1.currPosition() << endl;
            }
                break;
            case 5: {
                test1.moveToEnd();
                test2.moveToEnd();
                cout << "�ƶ���ǰλ��Ϊ: " << test1.currPosition() << endl;
            }
                break;
            case 6: {
                test1.prev();
                test2.prev();
                cout << "�ƶ���ǰλ��Ϊ: " << test1.currPosition() << endl;
            }
                break;
            case 7: {
                test1.next();
                test2.next();
                cout << "�ƶ���ǰλ��Ϊ: " << test1.currPosition() << endl;
            }
                break;
            case 8: {
                cout << "˳���ĳ���: " << test1.length() << endl;
                cout << "����ĳ���: " << test2.length() << endl;
            }
                break;
            case 9: {
                cout << "˳���ĵ�ǰλ��: " << test1.currPosition() << endl;
                cout << "����ĵ�ǰλ��: " << test2.currPosition() << endl;
            }
                break;
            case 10: {
                cout << "����Ҫ�ƶ�����λ�ã���'2': ";
                int pos;
                cin >> pos;
                test1.moveToPosition(pos);
                test2.moveToPosition(pos);
                cout << "�ƶ���ǰλ��Ϊ: " << test1.currPosition() << endl;
            }
                break;
            case 11: {
                cout << "˳���ĵ�ǰλ��Ԫ��ֵ: " << test1.getValue() << endl;
                cout << "����ĵ�ǰλ��Ԫ��ֵ: " << test2.getValue() << endl;
            }
                break;
            case 0:
                return;
            default:
                cout << "δ�����������������룡" << endl;
                break;
        }
    }

}

int game() {
    int n, k;
    cout << "����С���ѵ�����n����ָ̭��k���ÿո����" << endl;
    cin >> n >> k;
    Linked_List<int> circle;
    for (int i = 1; i <= n; i++) {
        circle.append(i);
    }
    circle.moveToStart();
    int tmp = 0;
    while (circle.length() != 1) {
        tmp++;
        cout << "��" << circle.getValue() << "λС���ѱ���" << tmp;
        if (tmp % k == 0 || tmp % 10 == k) {
            cout << "��̭";
            if (circle.currPosition() + 1 == circle.length()) {
                circle.remove();
                circle.moveToStart();
            }
            else
                circle.remove();
        }
        else {
            if (circle.currPosition() + 1 == circle.length())
                circle.moveToStart();
            else
                circle.next();
        }
        cout << endl;
    }
    circle.moveToStart();
    return circle.getValue();
}
