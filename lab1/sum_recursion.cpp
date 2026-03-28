#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

long long recursive_sum(int *a, int n) {   
    if (n == 1) {
        return a[0];
    }
    for(int i=0; i<n/2; i++){
        a[i] += a[n-i-1];   // 相邻元素相加连续存储到数组最前面，下一轮递归时只需处理前半部分
    }
    n/=2;
    return recursive_sum(a, n);
}

long long double_iter(int *a, int n) {
    for(int m=n; m>1; m/=2){    // 共需要log2(n)轮
        for(int i=0; i<m/2; i++){
            a[i] = a[i*2] + a[i*2+1];
        }
    }
    return a[0];  // 相邻元素相加连续存储到数组最前面，最后结果存储在a[0]中
}

double recursion_time(int *a, long long &sum, int n) {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);

    sum = recursive_sum(a, n);

    QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    double time = (double)(tail - head) / freq;
    return time;
}



int main() {
    int m=10000;
    
    int n;  
    cout << "Input array size: ";
    cin >> n;

    double time_sum = 0;

    for (int k = 0; k < m; k++) {        // 分配内存并初始化数组
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;  
        }

        long long sum = 0;      
        time_sum += recursion_time(a, sum, n);

        delete[] a;
    }
 
    cout << "Total time: " << time_sum << " seconds" << endl;
    cout << "Average time: " << time_sum / m << " seconds" << endl;
    
    return 0;
}

// 编译选项：
// g++ -O2 sum_recursion.cpp -o sum2.exe
