#include<iostream>
#include<math.h>
#include<stdlib.h> //函数exit()

typedef double (*pfn) (double);

class integral { //成员缺省为私有类型
    double lower;
    double upper;
    pfn integrand; //积分函数
public:
    integral (double a, double b, pfn f) {
        lower = a;
        upper = b;
        integrand = f;
    }
    double lowbd() const {return lower;}//常量函数
    double upbd() const{return upper;}//常量函数
    void changebd(double, double); //非常量函数
    double trapezoidal(int) const;
    friend double simpson(integral, int); //友元
};//不要忘记这个分号

inline void integral::changebd(double a, double b) {
    lower = a;
    upper = b;
}

double integral::trapezoidal(int n) const {
    double h = (upper - lower)/n;
    double sum = integrand(lower) *0.5;
    for (int i=1;i<n;i++) {
        sum += integrand(lower + i*h);
    }
    sum += integrand(upper)*0.5;
    return sum*h;
}
double simpson(integral ig, int n) {
    double h = (ig.upper - ig.lower)/n;
    double sum = ig.integrand(ig.lower)*0.5;
    for (int i=1;i<n;i++) {
        sum += ig.integrand(ig.lower +i*h);

    }
    sum += ig.integrand(ig.upper)*0.5;

    double summid = 0.0;
    for (int i=1;i<=n;i++) {
        summid += ig.integrand(ig.lower + (i-0.5)*h);
    }
    return (sum + 2*summid)*h/3.0;
}

int main(){
    integral di (0, 3.14,sin);
    double result = di.trapezoidal(100);
    std::cout << "Intrgral from " << di.lowbd() << " to " << di.upbd()
    << " is approximately = " << result << '\n';

    di.changebd(3,7);
    result = di.trapezoidal(100);
    std::cout << "Intrgral from " << di.lowbd() << " to " << di.upbd()
    << " is approximately = " << result << '\n';

    result = simpson(di, 200);
}