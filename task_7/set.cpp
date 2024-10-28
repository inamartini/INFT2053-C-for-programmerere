#include "set.hpp"
#include <iostream>
#include <algorithm>

// Constructor to create an empty set
Set::Set() = default;

// Copy constructor
Set::Set(const Set &other) : elements(other.elements) {}

// Function to find the union of two sets
Set Set::union_set(const Set &other) const {
    Set result = *this;  // Copy the current set
    for (int element : other.elements) {
        if (std::find(result.elements.begin(), result.elements.end(), element) == result.elements.end()) {
            result.elements.push_back(element);  // Add the element to the union set if not present
        }
    }
    return result;  // Return the union set
}

// Function to add a new element to the set
void Set::add_element(int element) {
    if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
        elements.push_back(element);  // Add the element if it's not already in the set
    }
}

// Function to assign one set to another
void Set::setAnotherSet(const Set &other) {
    elements = other.elements;  // Assign the elements from the other set
}

// Function to print the set
void Set::print() const {
    std::cout << "{";
    for (size_t i = 0; i < elements.size(); ++i) {
        std::cout << elements[i];
        if (i < elements.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}
