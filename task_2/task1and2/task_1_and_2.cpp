#include <iostream>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "i: Address = " << &i << " Value = " << i << endl;
    cout << "j: Address = " << &j << " Value = " << j << endl;
    cout << "p: Address = " << &p << " Value = " << p << " Pointing to = " << *p << endl;
    cout << "q: Address = " << &q << " Value = " << q << " Pointing to = " << *q << endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl;

    return 0;
}
