#include <iostream>

using namespace std;

// Template class for Pair of values
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    // Constructor
    Pair(T1 first, T2 second) : first(first), second(second) {}

    //Overload the + operator to add two Pair objects
    Pair operator+(const Pair &other) {
        Pair point = *this; // Copy the current object
        point.first += other.first; // Add the first values
        point.second += other.second; // Add the second values
        return point; // Return the new object
    }

    // Overload the > operator to compare the sum of the two Pair objects
    bool operator>(const Pair &other) {
        // Compare the sum of the two Pair objects
        return (this->first + this->second) > (other.first + other.second);
    }

    // Friend function to overload the << operator for printing a Pair
    friend ostream &operator<<(ostream &os, const Pair &pair) {
        // Output the pair in the format "(first, second)"
        return os << "(" << pair.first << ", " << pair.second << ")";
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/