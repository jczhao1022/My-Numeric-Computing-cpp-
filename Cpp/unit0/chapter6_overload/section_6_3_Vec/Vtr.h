#include<iostream>
#include<math.h>
#include<stdlib.h> //函数exit()
using namespace std;
class Vtr
{
private:
    /* data */
    int length;//元素个数
    double* ets;//向量元素
public:
    Vtr(int, double*); //构造函数
    Vtr(int = 0, double d = 0); //所有元素等于d
    Vtr(const Vtr&);//拷贝构造函数
    ~Vtr(){delete[] ets;};

    int size() const {return length;} // 返回长度
    Vtr& operator=(const Vtr&); //重载=
    Vtr& operator+=(const Vtr&);
    Vtr& operator-=(const Vtr&);
    double maxnorm() const;
    double twonorm() const;
    double& operator[](int i) const {return ets[i];} //下标
    friend Vtr operator+(const Vtr&);//一元+，v= +v2
    friend Vtr operator-(const Vtr&);//一元-
    friend Vtr operator+(const Vtr&, const Vtr&);//二元+
    friend Vtr operator-(const Vtr&, const Vtr&);//二元-
    friend Vtr operator*(double, const Vtr&);//a*v
    friend Vtr operator*(const Vtr&, double);//v*a
    friend Vtr operator/(const Vtr&, double);//v/a
    friend Vtr operator*(const Vtr&, const Vtr&); //v.*v
    friend double dot(const Vtr&, const Vtr&); //点积
    friend ostream& operator<<(ostream&, const Vtr&);
};
inline void error(char* v) {
    cout << v << ".program exit\n";
    exit(1);
}
Vtr::Vtr(int n, double* abd)//构造
{
    ets = new double [length = n];
    for (int i = 0; i < length; i++) {
        ets[i] = *(abd + i);
    }
}
Vtr::Vtr(int n, double a) {//构造
    ets = new double [length = n];
    for (int i = 0; i < length; i++) ets[i] = a;
}
Vtr::Vtr(const Vtr & v) {//拷贝构造
    ets = new double [length = v.length];
    for (int i = 0; i < length; i++) ets[i] = v[i];
}
Vtr& Vtr::operator=(const Vtr& v) {
    if (this != &v) {
        if (length != v.length) error("bad vetor sizes");
        for (int i = 0; i < length; i++) ets[i] = v[i];
    }
    return *this;
}
Vtr& Vtr::operator+=(const Vtr& v) {
    if (length != v.length) error("bad vetor sizes");
    for (int i = 0; i < length; i++) ets[i] += v[i];
    return *this;
}
Vtr& Vtr::operator-=(const Vtr& v) {
    if (length != v.length) error("bad vetor sizes");
    for (int i = 0; i < length; i++) ets[i] -= v[i];
    return *this;
}
inline Vtr operator+(const Vtr& v) {
    return v;
}
inline Vtr operator-(const Vtr& v) {
    return Vtr(v.length) - v;
}
Vtr operator+(const Vtr& v1, const Vtr& v2) {
    if (v1.length != v2.length) error("bad vetor sizes");
    Vtr sum = v1;
    sum += v2;
    return sum;
}
Vtr operator-(const Vtr& v1, const Vtr& v2) {
    if (v1.length != v2.length) error("bad vetor sizes");
    Vtr sub = v1;
    sub -= v2;
    return sub;
}
Vtr operator*(double a, const Vtr& v) {
    Vtr temp(v.length);
    for (int i = 0; i < v.length; i++) temp[i] = a*v[i];
    return temp;
}
Vtr operator*(const Vtr& v, double a) {
    return a*v;
}
Vtr operator*(const Vtr& v1, const Vtr& v2) {//点乘
    if (v1.length != v2.length) error("bad vetor sizes");
    int n = v1.length;
    Vtr temp(n);
    for (int i = 0; i < n; i++) temp[i] = v1[i]*v2[i];
    return temp;
}
Vtr operator/(const Vtr& v, double a) {
    if (!a) error("division by zero in vector-scalar division");
    return (1.0/a)*v;
}
double Vtr::twonorm() const {
    double norm = ets[0] * ets[0];
    for (int i = 1; i < length; i++) norm += ets[i]*ets[i];
    return sqrt(norm);
}
double Vtr::maxnorm() const {
    double norm = fabs(ets[0]);
    for (int i = 1; i < length; i++) norm = max(norm, fabs(ets[i]));
    return norm;
}
double dot(const Vtr& v1, const Vtr& v2) {
    if (v1.length != v2.length) error("bad vetor sizes");
    int n = v1.length;
    double res = v1[0] * v2[0];
    for (int i = 1; i < n; i++) res += v1[i]*v2[i];
    return res;
}
ostream& operator<<(ostream& s, const Vtr& v) {
    for (int i = 0; i < v.length; i++) {
        s << v[i] << " " ;
        if (i%10 == 9) s << '\n';//每行10个元素
    }
    return s;
}