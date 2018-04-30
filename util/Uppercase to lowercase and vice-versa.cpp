/*
https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
http://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
https://www.oreilly.com/library/view/c-cookbook/0596007612/ch04s13.html
*/
#include <string>
#include <iostream>
#include <algorithm> // for std::transform
using namespace std;

int main() {
    string s = "Abhijeet Kandalkar";

    // using iterators and transform
    transform(s.begin(), s.end(), s.begin(), ::toupper); cout << s << endl;
    transform(s.begin(), s.end(), s.begin(), ::tolower); cout << s << endl;

    // using iterator only
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        *itr = ::toupper(*itr);
    }
    cout << s << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        *itr = ::tolower(*itr);
    }
    cout << s << endl;

    // using foreach
    for_each(s.begin(), s.end(), [](char & c) { c = toupper(c);  }); cout << s << endl;
    for_each(s.begin(), s.end(), [](char & c) { c = tolower(c);  }); cout << s << endl;

    return 0;
}