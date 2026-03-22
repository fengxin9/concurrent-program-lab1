# include <iostream>
# include <windows.h>
using namespace std;

double matrix_product(int **mat, int *a, int *sum, int n) {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);  // 获取计时器频率
    QueryPerformanceCounter((LARGE_INTEGER *)&head);    // 计时器初始值

    for(int i=0;i<n;i++){
        sum[i] = 0;
        for(int j=0;j<n;j++){
            sum[i] += mat[j][i] * a[j];    
        }
    }
    QueryPerformanceCounter((LARGE_INTEGER *)&tail);    // 计时器结束值
    double time = (double)(tail - head) / freq;  // 计算运行时间

    return time;
}

const int n=100;

int main(){
    int m;
    cout << "Input test rounds:";
    cin >> m;
    double time_sum=0;

    for(int k=0; k<m; k++) {
    int **mat=new int*[n]; 
    for(int i=0; i<n; i++){
        mat[i] = new int[n];
        for(int j=0; j<n; j++){
            mat[i][j] = i + j;  // 填充测试数据
        }
    }
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i] = i;     // 初始化给定向量
    }

    /* 算法实现与计时 */
    int *sum=new int[n];        
    time_sum += matrix_product(mat, a, sum, n);


    /* 释放内存 */
    delete[] a;               
    delete[] sum;
    for(int i=0;i<n;i++){
        delete[] mat[i];
    }
    delete[] mat;
}
    cout << "Total time: " << time_sum << " seconds" << endl;
    cout << "Average time: " << time_sum / m << " seconds" << endl;

    return 0;
}

// 编译选项：g++ -O2 matrix_ordinary.cpp -o mo.exe