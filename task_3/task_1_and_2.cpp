//
// Created by Ina Martini on 11/09/2024.
//

#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
    Circle circle(5);

    double area = circle.get_area();
    cout << "Arealet er lik " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
}