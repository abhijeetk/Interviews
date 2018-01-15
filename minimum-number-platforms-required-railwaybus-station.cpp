#include <iostream>
#include <map>
#include <vector>

using namespace std;

int minimumPlatform(vector<int>& arr, vector<int>& dep) {
    multimap<int, int> m;

    for (int i = 0; i < arr.size(); i++) {
        m.insert(make_pair(arr[i], 1));
        m.insert(make_pair(dep[i], -1));
    }

    int platform_needed = 0;
    int result = 0;
    for (auto pair : m) {
        platform_needed += pair.second;
        if (platform_needed > result)
            result = platform_needed;
    }
    return result;
}

int main() {
    vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
    vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000 };

    cout << minimumPlatform(arr, dep) << endl;

    vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
    vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000 };

    cout << minimumPlatform(arr, dep) << endl;

    return 0;
}