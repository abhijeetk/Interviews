/*
    https://stackoverflow.com/questions/25298200/given-a-dictionary-and-a-list-of-letters-find-all-valid-words-that-can-be-built
*/
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class compareFunctor {
public :
    bool operator() (const int i, const int j) const {
        return i > j;
    }

};

vector<string> longestWord(string letters, vector<string> dic) {
     TEST:
    multimap<int, string, compareFunctor> mulMap;
    vector<string> res;
    int maxLength = 0;


    map<char, int> availableLettersMap;

     Traverse for each letter and store its frequency
    for (char c : letters) {
        auto itr = availableLettersMap.find(c);
        if (itr != availableLettersMap.end()) {
            found
            itr->second = itr->second + 1;
        }
        else {
             No found
            availableLettersMap.insert(make_pair(c, 1));
        }
    }

    for (auto itr = availableLettersMap.begin(); itr != availableLettersMap.end(); itr++)
        cout << itr->first << " : " << itr->second << endl;

     Traverse for each word in dictionary
    for (string s : dic) {
        map<char, int> usedLettersMap;
        bool validWord = true;
        for (char c : s) {
            auto itr = usedLettersMap.find(c);
            if (itr != usedLettersMap.end()) {
                found
                itr->second = itr->second + 1;
            }
            else {
                 No found
                usedLettersMap.insert(make_pair(c, 1));
            }

            int used = usedLettersMap[c];
            int avail = availableLettersMap[c];
            if ( used > avail) {
                validWord = false;
                break;
            }
        }

        if (validWord) {
             find longest
            while (!res.empty() && res.back().length() < s.length()) {
                res.pop_back();
            }
            res.push_back(s);

             find longest using multimap
            mulMap.insert(make_pair(s.length(), s));
            maxLength = s.length() > maxLength ? s.length() : maxLength;
        }
    }

    int count = mulMap.count(maxLength);
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> ret = mulMap.equal_range(4);
    auto ret = mulMap.equal_range(maxLength);
    for (auto i = ret.first; i != ret.second; i++) {
        cout << i->first << " : " << i->second << endl;
        ;
    }

    return res;
}

int main() {
    vector<string> dic = { "to", "toes", "toe", "doe", "dog", "god", "dogs", "gods" };
    vector<string> res = longestWord("ote", dic);
    for (string s : res) {
        cout << s << endl;
    }
    cout << "--------" << endl;
    res = longestWord("osetdgo", dic);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}