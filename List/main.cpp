/*
编译器需支持C++11标准，否则编译报错！！ 
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
                cout << "第" << game() << "位小朋友获胜!" << endl;
                break;
            case 0:
                return 0;
            default:
                cout << "未定义的命令，请重新输入！" << endl;
                break;
        }
    }
}
void menuStart() {
    cout << "===============选择要测试的数据集===============" << endl;
    cout << "===============1.Integer====================" << endl;
    cout << "===============2.Character==================" << endl;
    cout << "===============3.Double=====================" << endl;
    cout << "===============4.Bool=======================" << endl;
    cout << "===============5.String=====================" << endl;
    cout << "===============6.附加题的解答=================" << endl;
    cout << "===============0.退出程序=====================" << endl;
}

void menuFunction() {
    cout << "===============选择要测试的功能=================" << endl;
    cout << "| 1.新增元素(新建的线性表请先添加元素)" << endl;
    cout << "| 2.在当前位置插入元素" << endl;
    cout << "| 3.移除当前位置元素" << endl;
    cout << "| 4.移动到起始位置" << endl;
    cout << "| 5.移动到结束位置" << endl;
    cout << "| 6.移动到前一位置" << endl;
    cout << "| 7.移动到下一位置" << endl;
    cout << "| 8.返回线性表的长度" << endl;
    cout << "| 9.返回当前位置" << endl;
    cout << "| 10.移动到指定位置" << endl;
    cout << "| 11.返回当前位置元素值" << endl;
    cout << "| 0.测试结束，退出程序" << endl;
    cout << "=============================================" << endl;
}

template <typename T>
void test() {
    system("cls");
    int size = 0, tmp = 0;
    cout << "输入测试数据的规模，如'15': ";
    cin >> size;
    Array_List<T> test1(size);
    Linked_List<T> test2;
    while (true) {
        menuFunction();
        cin >> tmp;
        switch (tmp) {
            case 1: {
                cout << "输入要添加元素的个数: ";
                int size1;
                cin >> size1;
                cout << "输入要添加的元素，用空格分开: ";
                for (int i = 0; i < size1; i++) {
                    T temp;
                    cin >> temp;
                    test1.append(temp);
                    test2.append(temp);
                }
                cout << "添加后的线性表为: " << endl;
                cout << "顺序表: ";
                test1.print();
                cout << "链表: ";
                test2.print();
            }
                break;
            case 2: {
                cout << "输入要插入的元素: ";
                T temp;
                cin >> temp;
                test1.insert(temp);
                test2.insert(temp);
                cout << "插入后的线性表为: " << endl;
                cout << "顺序表: ";
                test1.print();
                cout << "链表: ";
                test2.print();
            }
                break;
            case 3: {
                test1.remove();
                test2.remove();
                cout << "移除当前位置元素后的线性表为: " << endl;
                cout << "顺序表: ";
                test1.print();
                cout << "链表: ";
                test2.print();
            }
                break;
            case 4: {
                test1.moveToStart();
                test2.moveToStart();
                cout << "移动后当前位置为: " << test1.currPosition() << endl;
            }
                break;
            case 5: {
                test1.moveToEnd();
                test2.moveToEnd();
                cout << "移动后当前位置为: " << test1.currPosition() << endl;
            }
                break;
            case 6: {
                test1.prev();
                test2.prev();
                cout << "移动后当前位置为: " << test1.currPosition() << endl;
            }
                break;
            case 7: {
                test1.next();
                test2.next();
                cout << "移动后当前位置为: " << test1.currPosition() << endl;
            }
                break;
            case 8: {
                cout << "顺序表的长度: " << test1.length() << endl;
                cout << "链表的长度: " << test2.length() << endl;
            }
                break;
            case 9: {
                cout << "顺序表的当前位置: " << test1.currPosition() << endl;
                cout << "链表的当前位置: " << test2.currPosition() << endl;
            }
                break;
            case 10: {
                cout << "输入要移动到的位置，如'2': ";
                int pos;
                cin >> pos;
                test1.moveToPosition(pos);
                test2.moveToPosition(pos);
                cout << "移动后当前位置为: " << test1.currPosition() << endl;
            }
                break;
            case 11: {
                cout << "顺序表的当前位置元素值: " << test1.getValue() << endl;
                cout << "链表的当前位置元素值: " << test2.getValue() << endl;
            }
                break;
            case 0:
                return;
            default:
                cout << "未定义的命令，请重新输入！" << endl;
                break;
        }
    }

}

int game() {
    int n, k;
    cout << "输入小朋友的数量n与淘汰指令k，用空格分离" << endl;
    cin >> n >> k;
    Linked_List<int> circle;
    for (int i = 1; i <= n; i++) {
        circle.append(i);
    }
    circle.moveToStart();
    int tmp = 0;
    while (circle.length() != 1) {
        tmp++;
        cout << "第" << circle.getValue() << "位小朋友报数" << tmp;
        if (tmp % k == 0 || tmp % 10 == k) {
            cout << "淘汰";
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
