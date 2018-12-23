#include <iostream>
#include <fstream>
#include <windows.h>
//#include <random> //随机数头文件

using namespace std;

int test1[256 * 1024] = {0};
int test2[256 * 1024] = {0};

template <typename T>
void BubbleSort(T arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void MaxHeapify(T arr[], int begin, int end) {
    int parent = begin;
    int child = parent * 2 + 1;
    while (child <= end) {
        if (child + 1 <= end && arr[child] < arr[child + 1])
            child++;
        if (arr[parent] > arr[child])
            return;
        else {
            swap(arr[parent], arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

template <typename T>
void HeapSort(T arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, i, len - 1);
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, 0, i - 1);
    }
}

int main() {
    ifstream in;
    ofstream out;
    string infile[5] = {
            "../test1.txt",
            "../test2.txt",
            "../test3.txt",
            "../test4.txt",
            "../test5.txt"
    };
    string outfile[5] = {
            "../respond1.txt",
            "../respond2.txt",
            "../respond3.txt",
            "../respond4.txt",
            "../respond5.txt"
    };

    for (int k = 0; k < 5; k++) {
        in.open(infile[k], ios::binary | ios::in);
        out.open(outfile[k], ios::out);

        int count = 0;
        while (!in.eof()) {
            int temp;
            in >> temp;
            test1[count] = test2[count] = temp;
            count++;
        }
        LARGE_INTEGER nFreq;
        LARGE_INTEGER nBeginTime;
        LARGE_INTEGER nEndTime;
        QueryPerformanceFrequency(&nFreq);
        QueryPerformanceCounter(&nBeginTime);

        //clock_t begin = clock();
        BubbleSort(test1, count);

        QueryPerformanceCounter(&nEndTime);
        //clock_t end = clock();
        out << "运行时间：" << ((double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart) * 1000 << "ms" << endl;
        out << "运行结果：" << endl;
        for (int i = 0; i < count; i++)
            out << test1[i] << ' ';

        out << endl;

        QueryPerformanceFrequency(&nFreq);
        QueryPerformanceCounter(&nBeginTime);
        //begin = clock();
        HeapSort(test2, count);

        QueryPerformanceCounter(&nEndTime);
        //end = clock();
        out << "运行时间：" << ((double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart) * 1000 << "ms" << endl;
        out << "运行结果：" << endl;
        for (int i = 0; i < count; i++)
            out << test2[i] << ' ';

        in.close();
        out.close();
    }
    return 0;
}

//生成随机数
//int main() {
//    string outfile[5] = {
//            "../test1.txt",
//            "../test2.txt",
//            "../test3.txt",
//            "../test4.txt",
//            "../test5.txt"
//    };
//    ofstream out;
//    default_random_engine random(static_cast<unsigned int>(time(nullptr)));
//    uniform_int_distribution<int> dis1(0, 500000);
//    out.open(outfile[4], ios::binary);
//    for(int i = 0; i < 256 * 1024; ++i)
//        out << dis1(random) << ' ';
//    out.close();
//    cout<<endl;
//}



// 100B = 25
// 1k   = 256
// 10k  = 2560
// 100k = 25600
// 1M   = 256 * 1024