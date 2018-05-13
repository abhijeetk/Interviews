#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> buildSuffixArray(string& str) {
    if (str.empty())
        return {};

    vector<std::pair<string, int>> suffixArr;
    for (int i = 0; i < str.size(); i++) {
        string suffix = str.substr(i);
        suffixArr.push_back(make_pair(suffix, i));
    }

    std::sort(suffixArr.begin(), suffixArr.end());

    vector<int> arr;
    for (auto s : suffixArr) {
        arr.push_back(s.second);
        cout << s.first << " : " << s.second << endl;
    }
    return arr;
}

void search(string pat, string txt, vector<int> suffArr) {
    int l = 0;
    int r = suffArr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        string t = txt.substr(suffArr[mid]);
        //https://stackoverflow.com/questions/7913835/check-if-one-string-is-a-prefix-of-another
        int res = strncmp(pat.c_str(), t.c_str(), pat.size()); // pattern should be first and 't; should be second

        if (res == 0) {
            cout << "Pattern found  : " << suffArr[mid] << endl;
            return;
        }

        if (res < 0)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << "Not found" << endl;
}

int main() {
    string s = "banana";
    vector<int> arr = buildSuffixArray(s);
    search("bana", s, arr); // O(m*log n) m : pattern length n : text length
    return 0;
}