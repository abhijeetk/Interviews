/*
Given a jumbled collection of segments, each of which is represented as a
Pair(startPoint, endPoint), this function sorts the segments to make a continuous path.
A few assumptions you can make:
1. Each particular segment goes in one direction only,
i.e.: if you see (1, 2), you will not see (2, 1).
2. Each starting point only have one way to the end point,
i.e.: if you see (6, 5), you will not see (6, 10), (6, 3), etc.

For example, if you're passed a list containing the following int arrays:
[(4, 5), (9, 4), (5, 1), (11, 9)]

Then your implementation should sort it such:
[(11, 9), (9, 4), (4, 5), (5, 1)]
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
class compare {
public :
    bool operator() (const int x, const int y) const {
        return x > y;
    }

};

vector<pair<int, int>> sortSegment(vector<pair<int, int>>& pArray) {
    map<int, int, compare> m;
    for (auto i : pArray) {
        m.insert(i);
    }

    pArray.clear();
    auto start = m.begin();
    pArray.push_back(make_pair(start->first, start->second));
    m.erase(start);

    while (!m.empty()) {
        pair<int, int> p = pArray.back();
        auto itr = m.find(p.second);
        if (itr != m.end()) {
            // found
            pArray.push_back(make_pair(itr->first, itr->second));
            m.erase(itr);
        }
        else {
            // Not found
        }
    }
    return pArray;
}

int main() {
    vector<pair<int, int>> pArray;
    pArray.push_back(make_pair(4, 5));
    pArray.push_back(make_pair(9, 4));
    pArray.push_back(make_pair(5, 1));
    pArray.push_back(make_pair(11, 9));
    vector<pair<int, int>> arr = sortSegment(pArray);
    for_each(pArray.begin(), pArray.end(), [](pair<int, int> p) {
        cout << "<" << p.first << ", " << p.second << ">" << endl;
    });
    return 0;

}
