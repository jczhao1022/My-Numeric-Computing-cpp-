#include<iostream>
using namespace std;

long factorical (int n ) {
    if (n == 0) return 1L;
    return n*factorical(n-1);
}
main(){
    int n = 3;
    long x = factorical(n);
    cout << x << '\n';
}