//
// Created by Ina Martini on 11/09/2024.
//

#ifndef OVING3_CIRCLE_H
#define OVING3_CIRCLE_H


class Circle {
public:
    Circle(double radius_);
    double get_area() const;
    double get_circumference() const;
private:
    double radius = 0.0;
};



#endif //OVING3_CIRCLE_H
