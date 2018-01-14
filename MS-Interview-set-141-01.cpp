/*
https://www.geeksforgeeks.org/microsoft-interview-experience-set-141-off-campus-online-coding-test-idc/

1) If the elements of index i and (i + 1) are equal then, double the value at index i
and replace the element at index(i + 1) with 0.

2) If the element at index i is 0, then ignore it.

3) Any number(element in an array) must be modified only once.

4) At the end, shift all the zeros(0s) to the right of the array and remaining
nonzeros to the left of the array.

Example:
Input: 2 2 0 4 0 8
Output: 4 4 8 0 0 0

Input: 2 2 0 4 0 2
Output: 4 4 2 0 0 0
*/
#include "iostream"
#include "vector"
using namespace std;

int replaceAndSwap(vector<int>& arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] == arr[i + 1]) {
            arr[i] = 2 * arr[i];
            arr[i + 1] = 0;
        }

        if (arr[i] == 0)
            continue;
    }

    int start = 0;
    int end = arr.size()-1;
    while(start < end) {
        if (arr[end] == 0)
            end--;

        if (arr[start] == 0 && arr[end] != 0) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            end--;
        }
        start++;
    }


    return 0;
}

int main()
{
    vector<int> arr = { 2, 2, 0, 4, 0, 8 };
    replaceAndSwap(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    cout << endl;
    arr.clear();
    arr = { 2, 2, 0, 4, 0, 2 };
    replaceAndSwap(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}
