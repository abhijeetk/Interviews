#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*
char findFirst(String input)

Finds the first character that does not repeat anywhere in the input string
- Given "apple", the answer is "a"
- Given "racecars", the answer is "e"
- Given "ababdc", the answer is "d
*/

char findFirst(string input) {
    unordered_map<char, int> m;
    for (char ch : input) {
        auto itr = m.find(ch);
        if (itr != m.end()) {
            // found
            itr->second = itr->second + 1;
        }
        else {
            // not found
            m.insert(make_pair(ch, 1));
        }
    }

    char res = 0;
    for (char ch : input) {
        auto itr = m.find(ch);
        if (itr->second == 1) {  // first char who has frequency 1
            res = itr->first;
            break;
        }
    }

    return res;
}

int main() {
    cout << findFirst("apple") << endl;
    cout << findFirst("racecars") << endl;
    cout << findFirst("ababdc") << endl;
    return 0;
}