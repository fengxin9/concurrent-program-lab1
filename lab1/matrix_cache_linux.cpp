#include <iostream>
#include <fstream>
#include <sys/time.h>   
#include <unistd.h>    
using namespace std;

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

double matrix_product(int **mat, int *a, long long *sum, int n, ofstream& outfile) {
    double start_time, end_time;
    
    start_time = get_time();  

    // 初始化结果数组
    for(int i = 0; i < n; i++) {
        sum[i] = 0;
    }  

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum[j] += mat[i][j] * a[i];
        }
    }
    
    // 将结果写入文件，防止编译器优化
    for(int i = 0; i < n; i++) {
        outfile << sum[i] << " ";
        if(i % 10 == 9) {
            outfile << endl;
        }
    }
    
    end_time = get_time();  
	double time = end_time - start_time; 

    return time;
}

int main() {
    int m;
    cout << "Input test rounds:";
    cin >> m;
    double time_sum = 0;

    int n;
    cout << "Input matrix size:";
    cin >> n;

    ofstream mat_ordinary_file("ordinary_results.txt");

    for(int k = 0; k < m; k++) {
        // 分配内存
        int **mat = new int*[n];
        for(int i = 0; i < n; i++) {
            mat[i] = new int[n];
            for(int j = 0; j < n; j++) {
                mat[i][j] = i + j;  // 填充测试数据
            }
        }
        
        int *a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = i;  // 初始化给定向量
        }

        // 算法实现与计时
        long long *sum = new long long[n]; 
		time_sum += matrix_product(mat, a, sum, n, mat_ordinary_file);

        // 释放内存
        delete[] a;
        delete[] sum;
        for(int i = 0; i < n; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    mat_ordinary_file.close();
    
    cout << "Total time: " << time_sum << " seconds" << endl;
    cout << "Average time: " << time_sum / m << " seconds" << endl;

	return 0;
}

// linux编译选项：
// g++ -O2 -march=native matrix_cache_linux.cpp -o mol
// g++ -O2 -pthread -o molpth matrix_cache_linux.cpp
// g++ -O2 -fopenmp -o molfo matrix_cache_linux.cpp

// ARM编译选项：
// aarch64-linux-gnu-g++ -static -o mol -march=armv8.2-a matrix_cache_linux.cpp
// aarch64-linux-gnu-g++ -static -O2 -pthread -o molpth matrix_cache_linux.cpp
// aarch64-linux-gnu-g++ -static -O2 -fopenmp -o molfo matrix_cache_linux.cpp

