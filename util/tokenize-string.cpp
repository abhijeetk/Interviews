#include <iostream>
#include <string>
#include <sstream> //string stream
#include <vector>

using namespace std;

vector<string> tokenize(string line, char delimeter) {
    istringstream iss(line);
    string token;
    vector<string> tokenList;
    while (getline(iss, token, delimeter)) {
        tokenList.push_back(token);
    }
    return tokenList;
}

int main() {
    string s = "Extreme programming is an emotional experience.";
    vector<string> res = tokenize(s, ' ');
    for (string t : res) {
        cout << t << endl;
    }
    cout << endl;
    res.clear();
    res = tokenize(s, 'e');
    for (string t : res) {
        cout << t << endl;
    }
    return 0;
}