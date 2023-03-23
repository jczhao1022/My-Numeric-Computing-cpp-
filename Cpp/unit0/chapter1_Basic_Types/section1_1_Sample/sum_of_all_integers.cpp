#include<iostream>
using namespace std;

main(){
    int n, m;
    cout << "Ebter teo integersL \n" ;
    cin >> n >> m;

    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }

    double sum = 0.0;

    for (int i = n; i <= m; i++) {
        sum += i;
    }

    cout << "Sum of intergers from " << n << " to " << m
         << " is: " << sum <<"\n" << endl;
}