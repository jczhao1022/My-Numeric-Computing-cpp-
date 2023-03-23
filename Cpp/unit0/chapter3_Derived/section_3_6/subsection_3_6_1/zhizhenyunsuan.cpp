#include<iostream>
using namespace std;
 main(){
    char* cc;
    cc = new char [3];

    cc[0] = 'a';
    cc[1] = 'b';
    cc[2] = 'c';

    char* p = &cc[0];
    char dd = *p;
    dd = *(cc + 2);

    cout << cc[0] << '\n';
    cout << dd << '\n';
 }