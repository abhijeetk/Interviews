/*
1) Given a list of words, group them by anagrams•
Input: List of "cat","dog","god"
Output:A Set of Sets of anagrams:
{'cat'}, {'dog','god'}

4) Implement the AnagramSolution group() method correctly.
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<list<string>> AnagramSolution(vector<string> words) {
    unordered_map<string, list<string>> m;
    for (auto w : words) {
        string key = w;
        std::sort(key.begin(), key.end());
        auto itr = m.find(key);
        if (itr != m.end()) {
            // found
            list<string> l = itr->second;
            l.push_back(w);
            itr->second = l;
        }
        else {
            // not found
            list<string> l;
            l.push_back(w);
            m.insert(make_pair(key, l));
        }
    }

    vector<list<string>> res;
    for (auto i : m) {
        list<string> l = i.second;
        res.push_back(l);
    }

    return res;
}

int main() {
    vector<string> words;
    words.push_back("cat");
    words.push_back("dog");
    words.push_back("god");
    words.push_back("listen");
    words.push_back("silent");
    vector<list<string>> res = AnagramSolution(words);

    for (auto l : res) {
        for (auto n : l) {
            cout << n << "\t";
        }
        cout << endl;
    }
}