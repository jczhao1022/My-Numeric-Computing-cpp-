#include <iostream>
using namespace std;

double f(int i) {
    return (i*i + (i -1)*(i-1) + (i-1)*(i-2))/3.14;
}

main(){
    int x = 4;
    float y = 3.14;
    double z = y + f(x);
    cout << "The value of z is: " << z << "\n";
}