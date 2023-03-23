#include<iostream>
using namespace std;

main(){
    int m = 3;
    int n = 3;
    double** tm = new double* [m];
    for (int i = 0; i < m; i = i +1) {
        tm[i] = new double [n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tm[i][j] = i*j;
        }
    }
    cout << tm[2][2]<<'\n';
    for (int i = 0; i<m; i++) {
        delete[] tm[i];
    }
    delete[] tm;

}