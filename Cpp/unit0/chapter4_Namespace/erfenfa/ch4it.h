#include<iostream>
#include<math.h>
#include<stdlib.h> //函数exit()

    const double delta = 1.0e-8;
    const double epsn = 1.0e-9;

    double bisctn0(double, double, double (*)(double), double, double);
    double bisection(double, double, double (*)(double), double, double, int);

    double fa(double);
    double fb(double);
    double fc(double);


