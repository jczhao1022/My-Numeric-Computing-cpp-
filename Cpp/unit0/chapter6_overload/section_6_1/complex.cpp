#include<iostream>
#include<math.h>
using namespace std;
class complex
{
private:
    /* 定义一个关于复数运算的类 */
    double re; //实部
    double im; //虚部
public:
    complex(/* args */double x = 0,double y=0) {re = x;im = y;}
    complex& operator+=(complex);
    complex& operator-=(complex);
    friend complex operator*(complex, complex);
    friend ostream& operator<<(ostream&, complex);
    friend istream& operator>>(istream&, complex&);
};
complex operator+(complex);
complex operator-(complex);
complex operator+(complex, complex);
complex operator-(complex, complex);

complex operator+(complex z) {
    return z;
}
complex operator-(complex z) {
    complex s;
    return s - z;
}
complex& complex::operator+=(complex z) {
    re += z.re;
    im += z.im;
    return *this;//类似于拷贝构造函数
}
complex& complex::operator-=(complex z) {
    re -= z.re;
    im -= z.im;
    return *this;//类似于拷贝构造函数
}
complex operator+(complex a, complex b) {
    return a += b;
}
complex operator-(complex a, complex b) {
    return a -= b;
}
complex operator*(complex a, complex b) {
    complex s(a.re*b.re - a.im*b.im, a.re*b.im + a.im*b.re);
    return s;
}
ostream& operator<<(ostream& s, complex z) {
    s << "(" <<z.re << "," << z.im << ")";
    return s;
}
istream& operator>>(istream& s, complex& z) {//传递引用
    s >> z.re >> z.im;
    return s;
}

int main(){
    complex a(1, 1);
    complex b = a;
    complex c = a + b;
    c -= b;
    cout << c <<'\n';
    c -= b;
    cout << - c+ a*b << '\n';
}