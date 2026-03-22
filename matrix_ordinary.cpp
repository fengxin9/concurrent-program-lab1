# include <iostream>
using namespace std;

int main(){
    int mat[100][100];  // 设置固定的测试数据，便于比较分析
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            mat[i][j] = i + j;  // 填充测试数据
        }
    }
    int a[100];
    for(int i=0;i<100;i++){
        a[i] = i;          // 初始化给定向量
    }
    int sum[100] = {0};
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            sum[i] += mat[j][i] * a[j];    // 计算内积
        }
    }
    return 0;
}