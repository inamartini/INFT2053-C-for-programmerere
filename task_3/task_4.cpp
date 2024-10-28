//
// Created by Ina Martini on 11/09/2024.
//

#include <iostream>
#include <string>

using namespace std;

int main() {

    // task a
    string word1;
    string word2;
    string word3;

    cout << "a)" << endl;
    cout << "Write three words: ";
    cin >> word1 >> word2 >> word3;

    // task b
    cout << "\nb)" << endl;
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "The sentence is: " << sentence << endl;

    // task c
    cout << "\nc)" << endl;
    cout << "The length of the first word is: " << word1.length() << endl;
    cout << "The length of the second word is: " << word2.length() << endl;
    cout << "The length of the third word is: " << word3.length() << endl;
    cout << "The length of the sentence is: " << sentence.length() << endl;

    // task d
    cout << "\nd)" << endl;
    string sentence2 = sentence;
    cout << "The sentence2 is: " << sentence2 << endl;

    // task e
    cout << "\ne)" << endl;
    for (size_t i = 10; i <= 12; i++) {
        if (sentence2[i]) {
            sentence2[i] = 'x';
        }
    }
    cout << "The sentence is: " << sentence << endl;
    cout << "The new sentence2 is: " << sentence2 << endl;

    // task f
    cout << "\nf)" << endl;
    string sentence_start;
    for (size_t i = 0; i < 5; i++) {
        if (sentence[i]){
            sentence_start += sentence[i];
        }
    }
    cout << "The first five characters of the sentence is: " << sentence_start << endl;
    cout << "The sentence is: " << sentence << endl;

    // task g
    cout << "\ng)" << endl;
    if (sentence.find("hallo") != string::npos) {
        cout << "The word 'hallo' is in the sentence" << endl;
    } else {
        cout << "The word 'hallo' is not in the sentence" << endl;
    }

    // task h
    cout << "\nh)" << endl;
    int count = 0;
    for (size_t i = 0; i < sentence.length(); i++) {
        if (sentence.find("er", i) != string::npos) {
            count++;
            i = sentence.find("er", i);
        }
    }
    cout << "The word 'er' is in the sentence " << count << " times" << endl;

    return 0;
}