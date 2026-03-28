#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

double sum_ord(int *a, long long &sum, int n, ofstream& outfile) {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    outfile << sum << endl;  // 将结果写入文件，防止编译器优化

    QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    double time = (double)(tail - head) / freq;
    return time;
}



int main() {
    int m=10000;
    
    int n;  
    cout << "Input array size: ";
    cin >> n;

    ofstream file("sum_results.txt");
    double time_sum = 0;

    for (int k = 0; k < m; k++) {        // 分配内存并初始化数组
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;  
        }

        long long sum = 0;      
        time_sum += sum_ord(a, sum, n, file);

        delete[] a;
    }

    file.close();  
    cout << "Total time: " << time_sum << " seconds" << endl;
    cout << "Average time: " << time_sum / m << " seconds" << endl;
    
    return 0;
}

// 编译选项：
// g++ -O0 sum_ordinary.cpp -o sum0.exe
// g++ -O sum_ordinary.cpp -o sum1.exe
// g++ -O2 sum_ordinary.cpp -o sum2.exe
// g++ -O3 sum_ordinary.cpp -o sum3.exe