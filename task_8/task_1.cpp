#include <iostream>

using namespace std;

// Template class for comparing values
template <typename Type>
bool testEqual(Type a, Type b) {
   cout << "Using template version: " << std::endl;
   cout << "Testing if " << a << " is equal to " << b << " :" << std::endl;
   if (a == b) {
       cout << "True" << std::endl;
       return true;
   } else {
       cout << "False" << std::endl;
       return false;
   }
}

// Specialization of CompareValues for double
template <>
bool testEqual(double a, double b) {
    cout << "Using specialized version for double: " << std::endl;
    cout << "Testing if " << a << " is equal to " << b << " :" << std::endl;
    if (a == b) {
        cout << "True" << std::endl;
        return true;
    } else {
        cout << "False" << std::endl;
        return false;
    }
}

int main() {
    cout << "\nTesting int values:\n" << std::endl;
    cout << testEqual(1, 2) << std::endl;
    cout << testEqual(1, 1) << std::endl;

    cout << "\nTesting string values:\n" << std::endl;
    cout << testEqual("Hello", "World") << std::endl;
    cout << testEqual("Hello", "Hello") << std::endl;

    cout << "\nTesting double values:\n" << std::endl;
    cout << testEqual(1.00001, 1.001) << std::endl;
    cout << testEqual(1.000001, 1.000001) << std::endl;

    return 0;
}
