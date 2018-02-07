/*
    Solution :
    https://www.geeksforgeeks.org/print-valid-words-possible-using-characters-array/
    Trie Implementation :
    https://www.geeksforgeeks.org/trie-memory-optimization-using-hash-map/
    StackOverflow :
    https://stackoverflow.com/questions/25298200/given-a-dictionary-and-a-list-of-letters-find-all-valid-words-that-can-be-built
*/
#include <string>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

// START : Trie
class TrieNode {
public :
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEndOfWord = false;
    }

    ~TrieNode() {
    }
};

void insert(TrieNode*& root, string str) {
    if (root == nullptr) {
        root = new TrieNode();
    }

    TrieNode* curr = root;
    for (char c : str) {
        auto itr = curr->children.find(c);
        if (itr == curr->children.end()) {
            // not found, then insert
            curr->children[c] = new TrieNode();
        }
        // move to already exist child
        curr = curr->children[c];
    }
    curr->isEndOfWord = true;
}

bool search(TrieNode* root, string str) {
    if (root == nullptr)
        return false;

    TrieNode* curr = root;
    for (char c : str) {
        auto itr = curr->children.find(c);
        if (itr != curr->children.end()) {
            // found
            curr = curr->children[c];
        }
        else
        {  // not found
            return false;
        }
    }
    // string exhausted 
    return curr->isEndOfWord;
}
// END : Trie

class compareFunctor {
public :
    bool operator() (const int i, const int j) const {
        return i > j;
    }

};

void longestWord(string letters, TrieNode* root, vector<string>& res, string& str) {
    if (root->isEndOfWord) {
        res.emplace_back(str);
    }

    for (int i = 0; i < letters.size(); i++) {
        char c = letters[i];
        auto itr = root->children.find(c);
        if (itr == root->children.end()) {
            // not found
        }
        else {
            // found
            //str.push_back(c);
            letters.erase(i, 1); // delete 1 char only from i'th position
            longestWord(letters, root->children[c], res, str+c);
            //str.pop_back();
        }
    }
}

int main() {
    vector<string> dic = { "to", "toes", "toe", "doe", "dog", "god", "dogs", "gods" };

    TrieNode* root = nullptr;
    for (string s : dic) {
        insert(root, s);
    }

    vector<string> res;
    string str;
    longestWord("ote", root, res, str);
    multimap<int, string> map;
    for (string s : res) {
        map.insert(make_pair(s.length(), s));
    }
    auto i = map.equal_range(map.rbegin()->first); // Retrive last pair with longest length; dont use map.end() as it never exists.
    for (auto itr = i.first; itr != i.second; itr++) {
        cout << itr->second << endl;
    }

    cout << "-----------" << endl;
    str.clear();
    res.clear();
    longestWord("osetdgo", root, res, str);
    multimap<int, string> map1;
    for (string s : res) {
        map1.insert(make_pair(s.length(), s));
    }
    auto ii = map1.equal_range(map1.rbegin()->first); // Retrive last pair with longest length
    for (auto itr = ii.first; itr != ii.second; itr++) {
        cout << itr->second << endl;
    }
    return 0;
}