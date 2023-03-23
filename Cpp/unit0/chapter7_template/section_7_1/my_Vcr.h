#include<iostream>
#include<math.h>
#include<stdlib.h> //函数exit()
#include<complex>
#include<algorithm>
using namespace std;

template<class T> class Vcr {
private:
    int lenth; //元素个数
    T* vr; //向量元素
public:
    Vcr(int, const T* const);//构造函数
    Vcr(int = 0, T = 0); //构造函数
    Vcr(const Vcr&); //拷贝构造函数
    ~Vcr(){delete[] vr; } //析构函数

    int size() const { return lenth;} //元素个数
    Vcr& operator=(const Vcr&); //赋值
    T& operator[](int i ) {return vr[i];} //下标
    Vcr& operator+=(const Vcr&); //v += v2
    T maxnorm() const;

    template<class S> //内积
    friend S dot(const Vcr<S>&, const Vcr<S>&);
};

template<class T> Vcr<T>::Vcr(int n, const T* const abd) {
    vr = new T [lenth = n];
    for (int i = 0; i < lenth; i++) vr[i] = *(abd + i);
}
template<class T> Vcr<T>::Vcr(int n, T a) {
    vr = new T [lenth = n];
    for (int i = 0; i < lenth; i++) vr[i] = a;
}

template<class T> Vcr<T>& Vcr<T>::operator=(const Vcr& v) {
    if (this != &v) {
        if (lenth != v.lenth) cout << "bad assignment of vector";
        for (int i = 0; i < lenth; i++) vr[i] = v[i];
    }
    return *this;
}

template<class T> Vcr<T>& Vcr<T>::operator+=(const Vcr& v) {
    if (lenth != v.lenth) cout << "bad assignment of vector";
    for (int i = 0; i < lenth; i++) vr[i] += v[i];
    return *this;
}

template<class T> T Vcr<T>::maxnorm() const {
    T nm = abs(vr[0]);
    for (int i = 1; i < lenth; i++) nm = max(nm, abs(vr[i]));
    return nm;
}

template<class T>
T dot(const Vcr<T>& v1, const Vcr<T>& v2) {
    if (v1.lenth != v2.lenth) cout << "bad vector sizes\n";
    T tm = v1[0]*v2[0];
    for (int i = 1; i < v1.lenth; i++) tm += v1[i]*v2[i];
    return tm;
}

//Vcr<T>的特化，元素为复数
template<class T> class Vcr <complex<T>> {
    int lenth;
    complex<T>* vr;
public:
    Vcr(int, const complex<T>* const);//构造函数
    Vcr(int = 0, complex<T> = 0);//构造函数
    Vcr(const Vcr&);//拷贝构造函数
    ~Vcr() { delete[] vr;} //析构函数

    int size() const {return lenth;}
    complex<T>& operator[](int i) const {return vr[i];}
    Vcr& operator+=(const Vcr&);
    Vcr& operator=(const Vcr&);
    T maxnorm() const;

    template<class S> friend complex<S>
    dot(const Vcr<complex<S> >&, const Vcr<complex<S> >&);
};

template<class T>
Vcr<complex <T>>::Vcr(int n, const complex<T>* const abd) {
    vr = new complex<T> [lenth = n];
    for (int i = 0; i < n; i++ ) vr[i] = *(abd + i);
}

template<class T>
Vcr<complex <T>>::Vcr(int n, complex<T> abd) {
    vr = new complex<T> [lenth = n];
    for (int i = 0; i < n; i++ ) vr[i] = abd;
}

template<class T>
Vcr<complex <T>>::Vcr(const Vcr& vec) {
    vr = new complex<T> [lenth = vec.lenth];
    for (int i = 0; i < lenth; i++) {
        vr[i] = vec[i];
    }
}

template<class T>
T Vcr<complex<T>>::maxnorm() const {
    T nm = abs(vr[0]);
    for (int i = 1; i < lenth; i++) nm = max(nm, abs(vr[i]));
    return nm;
}

template<class T>
complex<T> dot(const Vcr<complex<T>>& v1, const Vcr<complex<T>>& v2) {
    if (v1.lenth != v2.lenth) cout << "bad vector sizes \n";
    complex<T> tm = v1[0]*conj(v2[0]);
    for (int i = 1; i < v1.lenth; i++) {
        tm += v1[i]*conj(v2[i]);
    }
    return tm; 
}