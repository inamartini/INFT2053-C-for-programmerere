#pragma once
#include <vector>

class Set {
private:
    std::vector<int> elements;

public:
    Set();  // Constructor
    Set(const Set &other);  // Copy constructor
    Set union_set(const Set &other) const;  // Union of sets
    void add_element(int element);  // Add an element to the set
    void setAnotherSet(const Set &other);  // Assign one set to another
    void print() const;  // Print the set
};
