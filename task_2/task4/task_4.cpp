#include <iostream>

using namespace std;

int main() {
    int a = 5;

    // int &b;
    // Syntax error: A reference must refer to a valid object or function
    int &b = a;

    int *c;
    c = &b;

    // *a = *b + *c;
    // Syntax error: Invalid operands to binary expression ('int' and 'int')
    a = b + *c;

    //&b = 2;
    // Syntax error: Cannot assign to variable 'b' with const-qualified type 'const int &'
    b = 2;

    return 0;
}