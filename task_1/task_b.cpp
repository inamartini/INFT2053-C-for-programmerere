#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main(int, char**) {

    const int length = 5;
    double temperatures[length];

    int below10 = 0;
    int between10and20 = 0;
    int over20 = 0;

    read_temperatures(temperatures, length);

    for(int i = 0; i < length; i++) {
        cout << "Temperature number " << i + 1 << ": " << temperatures[i] << endl;

        if (temperatures[i] < 10) {
            below10++;
        } else if (temperatures[i] >= 10 & temperatures[i] <= 20) {
            between10and20++;
        } else if (temperatures[i] > 20) {
            over20++;
        }
    }
    cout << "Number of temperatures below 10 degrees: " << below10 << "\n";
    cout << "Number of temperatures between 10 and 20 degrees: " << between10and20 << "\n";
    cout << "Number of temperatures over 20 degrees: " << over20 << "\n";

    return 0;
}
void read_temperatures(double temperatures[], int length) {
    const char tempfile[] = "../temp.dat";
    ifstream file;
    file.open(tempfile);
    if(!file) {
        cout << "File could not open";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        double temp;
        file >> temp;
        temperatures[i] = temp;
    }
}


