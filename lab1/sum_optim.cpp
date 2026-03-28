#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

double two_chain(int *a, long long &sum, int n, ofstream& outfile) {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);

    long long sum1 = 0, sum2 = 0;
    for(int i=0; i<n; i+=2){  // 由于数组大小为2的幂次，所以无需考虑奇数情况
        sum1 += a[i];
        sum2 += a[i+1];
    }
    sum = sum1 + sum2;
    outfile << sum << endl;  

    QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    double time = (double)(tail - head) / freq;
    return time;
}

double four_chain(int *a, long long &sum, int n, ofstream& outfile) {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);

    long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for(int i=0; i<n; i+=4){  
        sum1 += a[i];
        sum2 += a[i+1];
        sum3 += a[i+2];
        sum4 += a[i+3];
    }
    sum = sum1 + sum2 + sum3 + sum4;
    outfile << sum << endl;  

    QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    double time = (double)(tail - head) / freq;
    return time;
}

double eight_chain(int *a, long long &sum8, int n, ofstream& outfile) {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);

    long long sum[8] = {0};
    for(int i=0; i<n; i+=4){  
       for(int j=0; j<8; j++){
            sum[j] += a[i+j];
        }
    }
    sum8 = sum[0] + sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6] + sum[7];
    outfile << sum8 << endl;  

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
        time_sum += two_chain(a, sum, n, file);

        delete[] a;
    }

    file.close();  
    cout << "Total time: " << time_sum << " seconds" << endl;
    cout << "Average time: " << time_sum / m << " seconds" << endl;
    
    return 0;
}

// 编译选项：
// g++ -O2 sum_optim.cpp -o sum2.exe
