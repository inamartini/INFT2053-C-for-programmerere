//
// Created by Ina Martini on 11/09/2024.
//

#include "Circle.h"

const double pi = 3.141592;

Circle::Circle(double radius_) {
    radius = radius_;
}

double Circle::get_area() const {
    return pi * radius * radius;
}

double Circle::get_circumference() const {
    return 2.0 * pi * radius;
}
