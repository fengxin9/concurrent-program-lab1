# include <iostream>
# include <windows.h>
# include <fstream>
using namespace std;

double matrix_product(int **mat, int *a, int *sum, int n, ofstream& outfile) {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);  // 获取计时器频率
    QueryPerformanceCounter((LARGE_INTEGER *)&head);    // 计时器初始值

    for(int i=0;i<n;i++){
        sum[i] = 0;
        for(int j=0;j<n;j++){
            sum[i] += mat[j][i] * a[j];    
        }
    }
    // 将结果写入文件，防止编译器优化
    for(int i = 0; i < n; i++) {
        outfile << sum[i] << " ";
        if(i % 10 == 9) {
            outfile << endl;
        }
    }
    
    QueryPerformanceCounter((LARGE_INTEGER *)&tail);    // 计时器结束值
    double time = (double)(tail - head) / freq;  // 计算运行时间

    return time;
}


int main(){
    int m;
    cout << "Input test rounds:";
    cin >> m;
    double time_sum=0;

    int n;
    cout << "Input matrix size:";
    cin >> n;

    ofstream mat_ordinary_file("ordinary_results.txt");

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
    time_sum += matrix_product(mat, a, sum, n, mat_ordinary_file);

    /* 释放内存 */
    delete[] a;               
    delete[] sum;
    for(int i=0;i<n;i++){
        delete[] mat[i];
    }
    delete[] mat;
}

    mat_ordinary_file.close();
    
    cout << "Total time: " << time_sum << " seconds" << endl;
    cout << "Average time: " << time_sum / m << " seconds" << endl;

    return 0;
}

// 编译选项：g++ -O matrix_ordinary.cpp -o mo.exe
// g++ -O2 matrix_ordinary.cpp -o mo2.exe
// g++ -O3 matrix_ordinary.cpp -o mo3.exe