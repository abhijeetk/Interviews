#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

void firstNonRepeatingChar(string s) {
    if (s.empty()) {
        cout << "ERROR" << endl;
    }

    // Hashmap to store frequency to decide repeatation.
    unordered_map<char, int> fequencyMap;

    // Queue to find first non-repeating number
    queue<int> q;
    for (char c : s) {
        if (fequencyMap.find(c) != fequencyMap.end()) { //found
            fequencyMap[c]++;
        }
        else {
            fequencyMap[c] = 1;
        }

        q.push(c);

        // for each character of string traverse complete queue to check 
        // if queue contains character with frequency 1.
        while (!q.empty()) {
            char c = q.front();
            if (fequencyMap[c] > 1) {
                q.pop();
            }
            else {
                cout << "->" << c << endl;
                break; // Break is needed as we found first non-repeating char for given char of input string
            }
        }

        if (q.empty()) {
            cout << "->" << -1 << endl;
        }
    }
}

int main() {
    char str[] = "aabc";
    firstNonRepeatingChar(str);
    return 0;
}