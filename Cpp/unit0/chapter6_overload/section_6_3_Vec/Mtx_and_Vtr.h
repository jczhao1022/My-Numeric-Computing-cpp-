#include"Vtr.h"

class Mtx
{
private:
    /* data */
    int nrows;
    int ncols;
    double** ets;
public:
    Mtx(int n, int m, double**);
    Mtx(int n, int m, double d = 0);
    Mtx(const Mtx&);
    ~Mtx();

    Mtx& operator=(const Mtx&);
    Mtx& operator+=(const Mtx&);
    Mtx& operator-=(const Mtx&);
    Vtr operator*(const Vtr&) const;
    double* operator[](int i) const { return ets[i];}
    double& operator()(int i, int j) { return ets[i][j];}

    Mtx& operator+() const;
    Mtx& operator-() const;
    Mtx operator+(const Mtx&) const;
    Mtx operator-(const Mtx&) const;

    int CG(Vtr& x, const Vtr& b, double& eps, int& iter);
    /*
    共轭梯度算法，解方程Ax=b
    成功返回0，否则返回1

    A: 对称正定矩阵
    b：方程右侧的向量
    x：初始值
    eps：开始时为停机准则，结束时为近似解的残差的二范数
    iter：开始时为最大允许迭代步数，结束时为实际迭代步数
    */
};
Mtx::Mtx(int n, int m, double** dbp) {
    nrows = n;
    ncols = m;
    ets = new double* [nrows];
    for (int i=0; i<nrows; i++) {
        ets[i] = new double [ncols];
        for (int j = 0; j < ncols; j++) {
            ets[i][j] = dbp[i][j];
        }
    }
}
Mtx::Mtx(int n, int m, double a) {
    nrows = n;
    ncols = m;
    ets = new double* [nrows];
    for (int i=0; i<nrows; i++) {
        ets[i] = new double [ncols];
        for (int j = 0; j < ncols; j++) {
            ets[i][j] = a;
        }
    }
}
Mtx::Mtx(const Mtx& mat) {
    ets = new double* [nrows = mat.nrows];
    ncols = mat.ncols;
    for (int i=0; i<nrows; i++) {
        ets[i] = new double [ncols];
        for (int j=0; j<ncols; j++) {
            ets[i][j] = mat[i][j];
        }
    }
}
inline Mtx::~Mtx(){
    for (int i=0; i<nrows; i++) delete[] ets[i];
    delete[] ets;
}
Mtx& Mtx::operator=(const Mtx& mat) {
    if (this != &mat) {
        if (nrows != mat.nrows || ncols != mat.ncols) {
            error("bad matrix size");
        }
        for (int i = 0; i < nrows; i++){
            for (int j = 0; j < ncols; j++) {
                ets[i][j] = mat[i][j];
            }
        }
        return *this;
    }
}
Mtx& Mtx::operator+=(const Mtx& mat) {
    if (nrows != mat.nrows || ncols != mat.ncols) error("bad matrix size");
    for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++) {
            ets[i][j] += mat[i][j];
        }
    }
    return *this;
}
Mtx& Mtx::operator-=(const Mtx& mat) {
    if (nrows != mat.nrows || ncols != mat.ncols) error("bad matrix size");
    for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++) {
            ets[i][j] -= mat[i][j];
        }
    }
    return *this;
}
inline Mtx& Mtx::operator+() const {
    Mtx sum = *this;
    return sum;
}
inline Mtx& Mtx::operator-() const {
    Mtx sum = Mtx(nrows, ncols);
    return sum -= *this;
}
Mtx Mtx::operator+(const Mtx& mat) const {
    if (nrows != mat.nrows || ncols != mat.ncols) error("bad matrix size");
    Mtx sum = *this;
    sum += mat;
    return sum;
}
Mtx Mtx::operator-(const Mtx& mat) const {
    if (nrows != mat.nrows || ncols != mat.ncols) error("bad matrix size");
    Mtx sum = *this;
    sum -= mat;
    return sum;
}
Vtr Mtx::operator*(const Vtr& v) const {
    if (ncols != v.size()) error("matrix and vector sizes do not match");
    Vtr tm(nrows);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            tm[i] += ets[i][j]*v[j];
        }
    }
    return tm;
}
int Mtx::CG(Vtr& x, const Vtr& b, double& eps, int& iter) {
    if (nrows != b.size()) cout << "matrix and vector sizes do not match\n";
    const int maxiter = iter;
    Vtr r = b - (*this)*x;
    Vtr p = r;
    double zr = dot(r, r);
    const double stp = eps*b.twonorm();

    if (r.twonorm() == 0) {
        //如果初始向量就是真解
        eps = 0.0;
        iter = 0;
        return 0;
    } 

    for (iter = 0; iter < maxiter; iter++) {
        Vtr mp = (*this)*p;
        double alpha = zr/dot(mp, p);
        x += alpha*p;
        r -= alpha*mp;
        if (r.twonorm() <= stp) break;

        double zr_old = zr;
        zr = dot(r, r);
        p = r + (zr/zr_old)*p;
    }

    eps = r.twonorm();
    if (iter == maxiter) return 1;
    else return 0;
}