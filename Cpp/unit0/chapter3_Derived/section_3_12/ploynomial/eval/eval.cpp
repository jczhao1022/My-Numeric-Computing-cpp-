#include<iostream>
#include<math.h>
using namespace std;

double eval (double* a, int n, double x) {
    double sum = 0;
    double temp;
    for (int k = n; k>=0; k--) {
        temp = pow(x, k);
        sum = sum + temp * a[k];
    }
    return sum;
}

double horner (double* a, int n, double x){
    double u = a[n];
    for (int k = n-1; k >=0; k--) {
        u = u * x + a[k];
    }
    return u;
}
main(){
    double a[9] = {1,-8,28,-56,70,-56,28,-8,1};
    for (double x = 0.99999; x<=1.0001; x+=1.0e-5){
        cout.width(18);
        cout<<eval(a,8,x);
        cout.width(18);
        cout<<horner(a,8,x);
        cout.width(18);
        cout<<pow(x-1,8) << '\n';
    }
}