#include <iostream>
using namespace std;
main(){
    int n = 10;
    cout << "The value of n is: " << n <<'\n';
    cout << "The location in memory of variable n is: " << &n << '\n';
    n = 55;
    cout << "The value of n is: " << n <<'\n';
    cout << "The location in memory of variable n is: " << &n << '\n';

}