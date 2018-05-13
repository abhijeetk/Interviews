#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrefix(string s1, string s2) {
    if (s1.empty() && s2.empty())
        return true;

    if (s1.empty() && !s2.empty())
        return true;

    if (!s1.empty() && s2.empty())
        return false;

    int res = strncmp(s1.c_str(), s2.c_str(), s1.size());
    if (res == 0)
        return true;
    else
        return false;
}

int isPrefixSTL(string str1, string str2) {
    auto res = std::mismatch(str1.begin(), str1.end(), str2.begin());
    if (res.first == str1.end())
        return true;
    else
        return false;
}

int main() {
    cout << isPrefix("comp", "computer") << endl;
    cout << isPrefix("Pre", "Prefix") << endl;
    cout << isPrefixSTL("comp", "computer") << endl;
    cout << isPrefixSTL("Pre", "Prefix") << endl;
    return 0;
}