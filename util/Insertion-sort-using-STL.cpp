#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addNum(vector<int>& store, int num) {
    if (store.empty())
        store.push_back(num);
    else
        // binary search and insertion combined
        store.insert(lower_bound(store.begin(), store.end(), num), num);
}

int main() {
    vector<int> store;
    addNum(store, 9);
    addNum(store, 7);
    addNum(store, 90);
    addNum(store, 1);
    addNum(store, 30);
    addNum(store, 2);
    for_each(store.begin(), store.end(), [](int i) {
        cout << i << endl;
    });

    return 0;
}