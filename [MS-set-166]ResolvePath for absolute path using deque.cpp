/*
    https://www.geeksforgeeks.org/microsoft-interview-experience-set-166/
    a/b/../c/d/e/…/f = > a/c/f = > count of . == n = > go back 
    (n - 1) time(directory path given)
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

// https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

string resolveDirPath(string str) {
    vector<string> strVec = split(str, '/');
    deque<string> s;

    // s is used as stack here
    for (auto it : strVec) {
        size_t sIndex = it.find_first_of('.');
        if (sIndex != string::npos) {
            size_t eIndex = it.find_last_of('.');
            size_t diff = eIndex - sIndex;
            while (diff > 0) {
                s.pop_front();
                diff--;
            }
        }
        else {
            s.push_front(it);
        }
    }

    string path;
    // s is used as queue here
    while (!s.empty()) {
        path.append(s.back());
        path.append("/");
        s.pop_back();
    }

    return path;
}

int main() {
    string str = "a/b/../c/d/e/.../f";
    cout << "Directoty path : " << resolveDirPath(str);
    return 0;
}