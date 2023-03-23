#include<iostream>
#include<math.h>
#include<stdlib.h> //函数exit()

typedef double (*pfn) (double) ;
double niudunfa(double xp, pfn f, pfn fd, double delta, double epsn, int maxit) {
    /***************************************************************
    newton's algorithm: 求方程f(x)=0 的根
    f：要求根的函数
    fd：一阶导数
    maxit：最大迭代步数
    delta：若相邻两次迭代找到的近似根之间的距离小于delta，则程序终止
    epsn：残差小于该值时，程序终止
    ****************************************************************/
   double v = f(xp);//初始估计
   double xnew;//保存新的根

   for (int k=1;k<=maxit;k++) {
    double derv = fd(xp); //xp处的导数
    if (derv == 0) {
        std::cout << "Division by 0 occured in newton().\n" ;
        exit(1);
    }

    xnew = xp - v/derv;
    v = f(xnew);
    if (fabs(xnew - xp) < delta || fabs(v)<epsn) return xnew;
    xp = xnew;
   }
   return xnew;
}

double testFun4Newton(double x) {
    return ((x-5)*x+3)*x+7;
}

double testFunD4Newton(double x) {
    return (3*x-10)*x+3;
}