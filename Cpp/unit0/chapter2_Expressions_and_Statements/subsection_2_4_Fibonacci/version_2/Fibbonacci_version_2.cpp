#include <iostream>
using namespace std;

main(){
    long fp = 1;
    long fc = 1;

    cout.width(2);
    cout << "n";
    cout.width(27);
    cout << "Fibbonacci number";
    cout.width(30);
    cout << "Fibbonacci quotient" << '\n\n';
    cout.precision(20);

    for (int n = 2; n <= 40; n++) {
        cout.width(2);
        cout << n;
        cout.width(27);
        cout << fc;
        cout.width(30);
        cout << (long double) fc/fp << '\n';

        long temp = fc;
        fc = fc + fp;
        fp = temp;
    }
}