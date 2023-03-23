#include"ch4it.h"

double bisctn0(double a, double b, double (*f)(double), double delta, double epsn){
    double c = (a+b)*0.5;
    if (fabs(b-a)*0.5 < delta || fabs(f(c)) <epsn ) return c;
    (f(a) * f(c) < 0) ? b=c:a=c;
    return bisctn0(a,b,f,delta,epsn);
}

double bisection(double a, double b, double(*f) (double), double delta, double epsn, int maxit) {
    /**************************************************
    bisection algm: 非递归版本，返回一个函数在指定区间内的近似解
    a, b: 指定区间的边界点，在这个区间内求解
    f：函数在区间[a,b]或[b,a]上有定义
    delta：根的容差，当区间大小小于该值时返回结果
    epsn：残差的容差，当残差小于该值时返回结果
    maxit：最大迭代步数
    **************************************************/
   double u = f(a);
   double e = b-a;
   double c;

   for (int k=1;k<=maxit;k++) {
    e = e*0.5; //区间减半
    c = a + e;//更新中点
    double w = f(c);//中点残差
    if (fabs(e) < delta || fabs(w) < epsn ) return c;
    ((u>0 && w <0) || (u<0 && w>0)) ? (b=c) : (a=c, u=w);
   }
   return c;
}

double fa(double x) {
    if (x) return 1.0/x - pow(2,x);
    else {
        std::cout << "division by zero occured in function fa().\n";
        exit(1);
    }
}

double fb (double x) {
    return pow(2,-x) + exp(x) +2*cos(x) - 6;
}

double fc (double x) {
    double denorm = ((2*x - 9)*x + 18)*x - 2;
    if (denorm) return (((x+4)*x+3)*x+5)/denorm;
    else {
        std::cout << "division by zero occured in function fc().\n";
        exit(1);
    }
}
