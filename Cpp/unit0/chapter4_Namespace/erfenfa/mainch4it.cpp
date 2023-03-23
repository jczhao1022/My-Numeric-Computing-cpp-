#include"ch4it.h"
int main(){
    double (*test_f) (double, double, double (*)(double), double, double);
    test_f = bisctn0;

    double root = test_f(1.0e-2, 1, fa, delta, epsn);
    std::cout << "Approximate root of fa() by bisctn0() is: " << root << '\n';
    std::cout << "Fcn value at approx root (resduial) is: " << fa(root) << '\n';

    root = test_f(1, 3, fb, delta, epsn);
    std::cout << "Approximate root of fb() by bisctn0() is: " << root << '\n';
    std::cout << "Fcn value at approx root (resduial) is: " << fb(root) << '\n';

    root = test_f(0, 4, fc, delta, epsn);
    std::cout << "Approximate root of fc() by bisctn0() is: " << root << '\n';
    std::cout << "Fcn value at approx root (resduial) is: " << fc(root) << '\n';

    root = bisection(1.0e-2, 1, fa, delta, epsn, 100);
    std::cout << "Approximate root of fa() by bisection() is: " << root << '\n';
    std::cout << "Fcn value at approx root (resduial) is: " << fa(root) << '\n';

    root = bisection(1, 3, fb, delta, epsn, 100);
    std::cout << "Approximate root of fb() by bisection() is: " << root << '\n';
    std::cout << "Fcn value at approx root (resduial) is: " << fb(root) << '\n';

    root = bisection(0, 4, fc, delta, epsn, 100);
    std::cout << "Approximate root of fc() by bisection() is: " << root << '\n';
    std::cout << "Fcn value at approx root (resduial) is: " << fc(root) << '\n';
}

