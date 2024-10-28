#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    // Task 1
    printf("\nTesting subtraction with integer:\n");
    Fraction e(1, 2);
    print("e = ", e);
    // Output: e = 1 / 2

    Fraction fraction1 = e - 5;
    print("fraction minus integer: f = ", fraction1);
    // Output: fraction1 = -9 / 2

    Fraction fraction2 = 5 - e;
    print("integer minus fraction: g = ", fraction2);
    // Output: fraction2 = 9 / 2

    Fraction f = 5 - 3 - fraction1 - 7 - fraction2;
    print("multiple subtractions: f = ", f);
    // Output: f = -5 / 1

    // TEORI, oppgave 1b)

    // En fraksjon med flere ledd (f = 5 - 3 - fraction1 - 7 - fraction2) vil bli regnet ut i flere ledd
    // 5 - 3 = 2 er en standard subtraksjon og bruker derfor en innebygd operator: int operator - (int, int)

    // 2 - fraction1 = 2 - (-9/2) = 4/2 + 9/2 = 13/2 er en subtraksjon med en fraksjon og bruker derfor en non-member
    // function: operator-(int, const Fraction&), som er definert i fraction.cpp

    // 13/2 - 7 = 13/2 - 14/2 = -1/2 er en subtraksjon med en fraksjon og bruker derfor en member function:
    // Fraction::operator - (int)

    // -1/2 - fraction2 = -1/2 - 9/2 = -10/2 = -5/1 er en subtraksjon med en fraksjon og bruker derfor
    // en member function: Fraction::operator - (const Fraction&)
}