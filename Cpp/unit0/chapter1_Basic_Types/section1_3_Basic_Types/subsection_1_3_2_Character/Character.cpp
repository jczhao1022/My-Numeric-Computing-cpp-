#include <iostream>
using namespace std;
main(){
    /*
    char c = 255;
    int i = c;
    cout << c << "\n" << i << '\n';
    */
    char c_1 = 'A';
    int i_1 = 'A';
    cout << c_1 << 'B' << i_1 << "CD" << '\n';
    int i_2 = sizeof("CD");
    int j_2 = sizeof("\n");
    int k_2 = sizeof('\n');
    cout << i_2 << j_2 << k_2 <<'\n';
}