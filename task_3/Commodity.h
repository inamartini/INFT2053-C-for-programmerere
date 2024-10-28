//
// Created by Ina Martini on 11/09/2024.
//

#ifndef OVING3_COMMODITY_H
#define OVING3_COMMODITY_H


class Commodity {
public:
    Commodity(const char* name, int id, double price);
    const char* get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(double quantity) const;
    void set_price(double new_price);
    double get_price_with_sales_tax(double quantity) const;
private:
    const char* name;
    int id;
    double price;
};



#endif //OVING3_COMMODITY_H
