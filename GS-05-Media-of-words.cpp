/*
    Given two words w1 and w2 in string s, find distance between
    location of centres of w1 and w2.
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int medianOfWords(string s, string w1, string w2) {
    // Assuming both w1 nad w2 are not null
    if (s.empty())
        return 0;

    if (s.length() == 1)
        return s.length();

    istringstream iss(s);
    string word;
    int f1 = -1;
    int f2 = -1;
    while (iss >> word) {
        //cout << word << endl;
        if (word == w1) {
            f1 = s.find(w1);
            f1 = f1 + w1.length() / 2;
        }

        if (word == w2) {
            f2 = s.find(w2);
            f2 = f2 + w2.length() / 2;
        }

        //cout << f1 << "\t" << f2 << endl;
    }

    int median;
    if (f1 == -1 || f2 == -1)
        median = -1;
    else
        median = f2 - f1;

    return median;
}

int main() {
    string s = "this is a sample document we just made up";
    int res = medianOfWords(s, "we", "just");
    cout << res << endl;
    res = medianOfWords(s, "is", "a");
    cout << res << endl;
    res = medianOfWords(s, "we", "not");
    cout << res << endl;
    return 0;
}