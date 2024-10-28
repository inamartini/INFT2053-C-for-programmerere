#include <iostream>
#include "set.hpp"

using namespace std;

int main() {
    // Define two empty sets
    Set set1;
    Set set2;

    // Add elements to the sets
    set1.add_element(1);
    set1.add_element(4);
    set1.add_element(3);
    set1.add_element(2);

    set2.add_element(2);
    set2.add_element(6);
    set2.add_element(3);

    // Print the sets
    cout << "Set 1: ";
    set1.print();

    cout << "Set 2: ";
    set2.print();

    // Find the union of the sets
    Set union_set = set1.union_set(set2);
    cout << "Union set: ";
    union_set.print();

    // New set as a copy of set1
    Set set3 = set1;

    // Print the new set
    cout << "Set 3 (copy of set1): ";
    set3.print();

    // Set the new set to be a copy of set2 and print
    set3 = set2;
    cout << "Set 3 (copy of set 2): ";
    set3.print();

    return 0;
};