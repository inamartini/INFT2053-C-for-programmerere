#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    // a)
    cout << "a) " << endl;
    // Find the first element in v1 that is greater than 15 using find_if
    auto it = find_if(v1.begin(), v1.end(), [](int i) { return i > 15; });
    cout << "First element in v1 greater than 15: " << *it << endl;

    // b)
    cout << "b) " << endl;
    // Find if v1 and v2 are almost equal (the difference between the elements is less than 2) using equal
    bool almostEqual = equal(v1.begin(), v1.begin() + 5, v2.data(), [](int a, int b){
                                return abs(a - b) < 2;});
    cout << "The interval [v1.begin(), v1.begin() + 5] and v2 are almost equal: " << almostEqual << endl;
    bool almostEqual2 = equal(v1.begin(), v1.begin() + 4, v2.data(), [](int a, int b){
        return abs(a - b) <= 2;});
    cout << "The interval [v1.begin(), v1.begin() + 4] and v2 are almost equal: " << almostEqual2 << endl;

    // c)
    cout << "c) " << endl;
    // Replace all odd numbers in v1 with 100 using replace_if
    vector<int> v3 = v1; // Copy v1 to v3
    v3.resize(v1.size());

    replace_if(v3.begin(), v3.end(), [](int i) { return i % 2 != 0; }, 100);
    cout << "v1 after replacing all odd numbers with 100: " << v3 << endl;
}
