#include<iostream>
#include<math.h>
using namespace std;

typedef double (*pfn)(double);

double trapezoidal(double a,double b, pfn f, int n) {
    double h = (b -a)/n;
    double sum = f(a)*0.5;
    for (int i = 1; i < n; i++) {
        sum = sum + f(a + i*h);
    }
    sum += f(b);
    return sum*h;
}

double simpson (double a, double b, pfn f, int n) {
    double h = (b-a) / n;
    double sum = f(a)*0.5;
    for (int i = 1; i <n; i++) {
        sum += f(a +i*h);
    }
    sum += 0.5*f(b);

    double summid = 0;
    for (int i = 1 ; i < n; i++) {
        summid += f(a+(i-0.5)*h);
    }

    return (sum + 2*summid)*h/3.0;
}

double square (double d) {return d*d;}

main(){
    double result = trapezoidal(0, 5, square, 100);
    cout << '\n';
    cout << "Integral using trapezpidal with n = 100 is: " << result << '\n';

    result = simpson(0, 5, square, 100);
    cout << "Integral using simpson with n = 100 is: " << result << '\n';

    result = trapezoidal(0, 5, sqrt, 100);
    cout << "Integral using trapezpidal with n = 100 is: " << result << '\n';

    result = simpson(0, 5, sqrt, 100);
    cout << "Integral using simpson with n = 100 is: " << result << '\n';
    cout << "  " <<'\n';
}