#include<iostream>
#include<math.h>
#include<stdlib.h> //函数exit()
class ode {
    double tini; //初始时间
    double ison; //初始解
    double tend;//结束时间
    double (*sfn) (double t,double x);
public:
    ode (double t0, double x0, double T, double (*f) (double, double)) {
        //构造函数
        tini = t0;
        ison = x0;
        tend = T;
        sfn = f;
    }
    double* euler(int n) const;//显式欧拉

};
double* ode::euler(int n) const {
    double* x = new double [n+1]; //近似解
    double h = (tend - tini)/n;//步长
    x[0] = ison;//初始解
    for (int k = 0; k<n; k++) {
        x[k+1] = x[k] + h*sfn(tini + k*h, x[k]);
    }
    return x;
}
double f(double t, double x) {
    return x*(1 - exp(t))/(1 + exp(t));
}
double exact(double t) {
    return 12*exp(t)/pow(1 + exp(t), 2);
}

int main(){
    ode exmp(0,3,2,f);
    double* soln = exmp.euler(100);

    double norm = 0;
    double h = 2.0/100;
    for (int k = 1; k <= 100; k++) {
        norm = std::max(norm, fabs(exact(k*h) - soln[k]));
    }
    std::cout << "max norm of error by euler's method = " << norm << '\n';
}