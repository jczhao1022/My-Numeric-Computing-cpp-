#include<iostream>
using namespace std;

double* mxvrmy(double** const mx, double* vr, int n, int m){
    double* tmv = new double[n];
    for (int i=0; i<n; i++) {
        tmv[i] = 0;
        for (int j=0;j<m;j++) {
            tmv[i] = tmv[i] + mx[i][j] * vr[j];
        }
    }
    return tmv;
}

main(){
    int n = 100, m= 200;

    // 给矩阵A 分配内存
    double** A = new double* [n];
    for (int i =0; i<n;i++) {
        A[i] = new double [m];
    }
    // 给向量x 分配内存
    double* x = new double [m];

    // 给矩阵赋值
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            A[i][j] = i*i + j;
        }
    }
    //给向量赋值
    for (int j=0; j<m; j++){
        x[j] = 3*j + 5;
    }
    //计算矩阵向量乘积
    double* b = mxvrmy(A, x, n, m);
    //计算b 的二范数平方
    double sum = 0;
    for (int i=0;i<n;i++) {
        sum = sum + b[i]*b[i];
    }
    //输出
    cout << sum <<'\n';
    //回收空间
    for (int i = 0;i<n; i++){
        delete[] A[i];
    }
    delete[] A;
    
    delete[] x; 
    delete[] b;
}