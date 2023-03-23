#include"my_Vcr.h"

int main(){
    int n = 300;
    complex<double>* aa = new complex<double> [n];
    for (int j = 0; j < n; j++) aa[j] = complex<double>(5, j);
    Vcr<complex<double>> v1(n, aa);

    Vcr<complex<double>> v2(n);
    for (int j = 0; j < n; j++) v2[j] = complex<double>(2, 3+j);

    cout << "norm " << v1.maxnorm() << '\n';//计算无穷范数

    cout << "dot " << dot(v1, v2) << '\n';//计算内积
}