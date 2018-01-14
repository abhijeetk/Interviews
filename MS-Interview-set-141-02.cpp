/*
    https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
*/
#include <iostream>
#include <vector>
using namespace std;

int maxDiff(vector<int>& vec) {
    int minIndex = 0;
    int min_element = vec[0];

    int maxIndex = 1;
    int max_diff = vec[1] - vec[0];
    int maxIndexDiff = -1;

    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] - min_element > max_diff) {
            max_diff = vec[i] - min_element;
            maxIndex = i;
            maxIndexDiff = maxIndex - minIndex;
        }

        if (vec[i] < min_element) {
            min_element = vec[i];
            minIndex = i;
        }
    }
    //cout << "minIndex : " << minIndex << "\t maxIndex : " << maxIndex << "\t IndexDiff : " << maxIndexDiff << endl;
    return maxIndexDiff;
}

int main() {
    vector<int> vec = { 1, 2, 6, 80, 100 };
    cout << maxDiff(vec) << endl;

    vec.clear();
    vec = { 2, 0, 3, 5, 6, 1 };
    cout << maxDiff(vec) << endl;

    vec.clear();
    vec = { 9, 8, 7, 6, 5 };
    cout << maxDiff(vec) << endl;

    return 0;
}