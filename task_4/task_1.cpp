#include <iostream>
#include <vector>

int main() {

    // Vector with five doubles
    std::vector<double> v = {1.0, 2.2, 3.2, 4.4, 5.9};

    // Using the front and back functions
    std::cout << "First element: " << v.front() << std::endl;
    std::cout << "Last element: " << v.back() << std::endl;

    // Using the emplace function
    v.emplace(v.begin() + 1, 1.9);

    // Printing the first element after using emplace
    std::cout << "First element after emplace: " << v.front() << std::endl;

    // defining a double to search
    double search = 3.2;

    // Using the find function to search
    auto it = std::find(v.begin(), v.end(), search);
    if (it != v.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
