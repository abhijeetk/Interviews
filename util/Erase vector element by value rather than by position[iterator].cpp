/*
    https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
    http://en.cppreference.com/w/cpp/algorithm/remove
    https://www.geeksforgeeks.org/difference-between-stdremove-and-vectorerase-for-vectors/
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype> // isspace
using namespace std;

int main() {
    std::string str1 = "Text with some   spaces";
    auto itr = std::remove(str1.begin(), str1.end(), ' ');
    // return result point to "paces"
    cout << std::distance(itr, str1.begin()); // 18

    cout << "After removal : " << endl;
    for (auto p = str1.begin(); p != itr; ++p) // itr points to 18th char
        std::cout << *p; //"Textwithsomespaces"
    std::cout << endl;

    cout << "After erase : " << endl;
    str1.erase(itr, str1.end()); // delete all char from 18th position to end
    std::cout << str1 << '\n';

    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(str2.begin(),
        str2.end(),
        [](unsigned char x) {return std::isspace(x); }),
        str2.end());
    std::cout << str2 << '\n';
}