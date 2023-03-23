#include <iostream>
using namespace std;

main(){
    long fp = 1;
    long fc = 1;

    for (int n = 2; n <= 40; n++) {
        cout << n << "  ";
        cout << fc << "  ";
        cout << (long double) fc/fp << '\n';

        long temp = fc;
        fc = fc + fp;
        fp = temp;
    }
}