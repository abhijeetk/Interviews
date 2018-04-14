// https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
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

    // deque to find first non-repeating number
    deque<char> q;
    for (char c : s) {
        if (fequencyMap.find(c) != fequencyMap.end()) { //found
            fequencyMap[c]++;
            if (fequencyMap[c] == 2) {
                // c is seen second time. Remove the node of deque
                for (auto it = q.begin(); it != q.end(); it++) {
                    if (*it == c) {
                        q.erase(it);
                        break;
                    }
                }
            }
        }
        else {
            // c is seen first time. Append x to deque
            fequencyMap[c] = 1;
            q.push_back(c);
        }

        if (q.empty()) {
            cout << "->" << -1 << endl;
        }
        else {
            cout << "->" << q.front() << endl;
        }
    }
}

int main() {
    char str[] = "geeksforgeeksandgeeksquizfor";
    //firstNonRepeatingChar(str);

   string str1 = "geeekskgm";
    firstNonRepeatingChar(str1);

    return 0;
}