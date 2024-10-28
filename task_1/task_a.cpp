#include <iostream>
using namespace std;

int main(int, char**) {
    const int length = 5;
    int temperature[length];
    int number = 0;
    int below10 = 0;
    int between10and20 = 0;
    int over20 = 0;

    for (int & i : temperature) {
        number++;
        cout << "Temperature number " << number << ": ";
        cin >> i;
        if (i < 10) {
            below10++;
        } else if (i >= 10 & i <= 20) {
            between10and20++;
        } else if (i > 20) {
            over20++;
        }
    }
    cout << "Number of temperatures below 10 degrees: " << below10 << "\n";
    cout << "Number of temperatures between 10 and 20 degrees: " << between10and20 << "\n";
    cout << "Number of temperatures over 20 degrees: " << over20 << "\n";

    return 0;
}
