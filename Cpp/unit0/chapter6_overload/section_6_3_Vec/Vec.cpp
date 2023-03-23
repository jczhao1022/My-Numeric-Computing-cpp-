#include"Mtx_and_Vtr.h"

void f(){
    int m = 500;
    double* v = new double [m];
    for (int i = 0; i < m; i++) v[i] = i*i + 10;
    Vtr v1(m, v);
    Vtr v2(m);
    for (int i = 0; i < m; i++) v2[i] = 5*i - 384;
    Vtr v3(m, 5.8);

    Vtr v4 = -v1 + 3.3*v3;
    v4 += v2;
    cout << v4;

    Vtr v5 = - v1*v4;
    double a = dot(v1, v5);
    cout << a <<'\n';
}
void g(){
    int k = 3;
    double** mt = new double* [k];
    for (int i=0; i<k; i++) mt[i] = new double [k];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            mt[i][j] = 2*i*j + i + 10;
        }
    }

    Mtx m1(k, k, mt);
    Mtx m2(k, k, 5);
    Mtx m3(k, k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            m3[i][j] = 1.0/(2*i + j + 5.7);
        }
    }

    m3 += - m1 + m2;
    m1 -= m3;

    Vtr vv(k);
    for (int i = 0; i < k; i++ ) vv[i] = 5*i +3;
    vv = m3*vv;
    cout << vv;
}
void test4CG(){
    int n = 300;
    Mtx A(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1.0/(i+j+1.0);//Hilbert matrix
        }
    }
    Vtr exat(n); //真解
    for (int i = 0; i<n; i++) {
        exat[i] = 1.0/(i + 3.14);
    }
    Vtr x(n); //初始

    int iter = n;
    double eps = 1.0e-9;

    int ret = A.CG(x, A*exat, eps, iter);

    if (ret == 0) cout << "CG returned successfully. \n";

    cout << iter << " iterations are used in CG method. \n" ;
    cout << "Residual = " << eps << ".\n";
    cout << "Twonorm of error vector = " << (x - exat).twonorm() << ".\n";
}
int main(){
    //f(); //测试向量类Vtr
    //g(); //测试矩阵类Mtx
    //测试共轭梯度
    test4CG();
}