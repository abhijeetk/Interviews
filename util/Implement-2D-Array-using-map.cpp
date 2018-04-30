/*
    If 2D array entries are too much sparsed then memory wastage is more.
    Implementing 2D array using map provide memory optimization
*/
#include <iostream>
#include <unordered_map>
using namespace std;

// arr[row][col] = val

int main() {
    unordered_map<int, unordered_map<int, int>> arr;
    // arr[0][0] = 1
    int row = 3;
    int col = 3;
    int count = 1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = count;
            count++;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}