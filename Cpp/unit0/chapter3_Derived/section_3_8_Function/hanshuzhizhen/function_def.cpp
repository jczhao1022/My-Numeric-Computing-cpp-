/*通过函数指针，便捷计算积分近似值*/
#include<iostream>
using namespace std;

double square(double d) {
    return d*d;
    }
typedef double (*coef)(double);
double integral(coef f, double a, double b) {
    return f((a+b)*0.5)*(b - a);
}

main(){
    coef sfp = square;

    double v = integral(sfp, 2, 2.01);

    cout << v << '\n';
    }