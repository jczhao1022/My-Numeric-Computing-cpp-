#include"newton.h"
int main(){
    double root = niudunfa(5, testFun4Newton, testFunD4Newton, 1e-8,1e-9,500);
    std::cout<<"Approx root near 5 by newton method is: " << root << '\n';
    std::cout<<"Fun value at approxmate root (residual) is: " << testFun4Newton(root) <<'\n';
}
