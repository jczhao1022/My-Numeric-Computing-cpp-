#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

namespace Vec {
    const int maxsize = 1e5;
    double onenorm(const double* const, int); //l_1 norm
    double twonorm(const double* const, int); //l_2 norm
    double twonorm_robust(const double* const, int); //l_2 norm
    double maxnorm(const double* const, int); //infinte norm
}

double Vec::onenorm(const double* const v, int size) { //计算1 范数
    if (size > maxsize) {
        cout << "Vector size too large " << '\n';
    }
    double norm = fabs(v[0]);
    for (int i = 1; i <size; i ++) {
        norm += fabs(v[i]);
    }
    return norm;
}

double Vec::maxnorm(const double* const v, int size) { //计算无穷 范数
    if (size > maxsize) {
        cout << "Vector size too large " << '\n';
    }
    double norm = fabs (v[0]);
    for (int i = 0; i <size; i ++) {
        norm = max(norm, fabs(v[i]));
    }
    return norm;
}

double Vec::twonorm(const double* const v, int size) { //计算2 范数
    if (size > maxsize) {
        cout << "Vector size too large " << '\n';
    }
    double norm = v[0] * v[0];
    for (int i = 1; i <size; i ++) {
        norm += v[i] * v[i];
    }
    return sqrt(norm);
}

double Vec::twonorm_robust(const double* const v, int size) { //计算2 范数，一种robust 的算法，但是效率不高
    if (size > maxsize) {
        cout << "Vector size too large " << '\n';
    }
    double norm = fabs(v[0]);
    for (int i=1; i<size;i++) {
        double avi = fabs(v[i]);
        if (norm < 100 && avi < 100) {
            norm = sqrt(norm * norm + avi * avi);
        }
        else if (norm > avi) {
            norm = norm * sqrt(1 + pow(avi/norm, 2));
        }
        else {
            norm = avi * sqrt(1 + pow(norm/avi, 2));
        }
    }
    return norm;
}

namespace Mat {
    double onenorm(const double* const*, int); //l_1 norm
    //double twonorm (const double** const, int); //l_2 norm
    double maxnorm(const double* const*, int); //l_0 norm
    double frobnorm(const double* const*, int); //F norm
    double frobnorm_robust(const double* const*, int); //F norm
}

double Mat::maxnorm(const double* const* A, int size) {
    double norm = Vec::onenorm(A[0], size);
    for (int i = 0; i<size; i++) {
        norm = max(norm, Vec::onenorm(A[i], size));
    }
    return norm;
}

double Mat::onenorm (const double* const* A, int size) {
    double norm = 0; 
    for (int j = 0; j<size;j++) {
        double temp = 0;
        for (int i=0; i<size; i++) {
            temp += A[i][j];
        }
        norm = max(norm, temp);
    }
    return norm;
}

double Mat::frobnorm (const double* const* A, int size) {
    double norm = 0;
    for (int i =0; i<size; i++) {
        for (int j = 0; j<size;j++) {
            norm += A[i][j] * A[i][j];
        }
    }
    return sqrt(norm);
}

double Mat::frobnorm_robust (const double* const* A, int size) {
    double norm = 0;
    for (int i =0; i<size; i++) {
        for (int j = 0; j<size;j++) {
            double avi = fabs(A[i][j]);
            if (norm < 100 && avi < 100) {
                norm = sqrt(norm * norm + avi * avi);
            }
            else if (norm > avi) {
                norm = norm * sqrt(1 + pow(avi/norm, 2));
            }
            else {
                norm = avi * sqrt(1 + pow(norm/avi, 2));
            }
        }
    }
    return norm;
}

main(){
    int n = 10;
    double** A = new double* [n];
    for (int i = 0;i<n;i++) {
        A[i] = new double [n];
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            A[i][j] = 1.0/(i+j+1);
        }
    }
    double s1 = Mat::maxnorm(A,n);
    double s2 = Vec::maxnorm(A[1],n);
    cout << s1 <<'\n';
    cout << s2 <<'\n';
    //cout << "wefwfwf" << '\n';
}