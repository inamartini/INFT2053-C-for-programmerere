#include <iostream>
using namespace std;

int main() {
    double number ;
    double *p = &number;
    double **pp = &p;

    number = 3.14;
    cout << "number: " << number << endl;

    *p = 4.15;
    cout << "number: " << number << endl;

    **pp = 1.09;
    cout << "number: " << number << endl;
}
