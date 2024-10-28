//
// Created by Ina Martini on 11/09/2024.
//

#include "Commodity.h"

Commodity::Commodity(const char* name, int id, double price) {
    this->name = name;
    this->id = id;
    this->price = price;
}

const char* Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(double quantity) const {
    return price * quantity;
}

void Commodity::set_price(double new_price) {
    this->price = new_price;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return price * quantity * 1.25;
}