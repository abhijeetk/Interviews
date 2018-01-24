#include <iostream>
#include <vector>
using namespace std;

// Given 2D array find sum of adjacent element for arr[x][y]

bool isValidIndex(int i, int j, int rowlen, int colLen) {
    if(i < rowlen && j < colLen && i >= 0 && j >= 0)
        return true;

    return false;
}

int adj_sum(int array[][5], int num_rows, int num_cols, int i, int j) {

    // Coded
    int sum = 0;
    sum += isValidIndex(i - 1, j - 1, num_rows, num_cols) ? array[i - 1][j - 1] : 0;
    sum += isValidIndex(i, j - 1, num_rows, num_cols) ? array[i][j - 1] : 0;
    sum += isValidIndex(i + 1, j - 1, num_rows, num_cols) ? array[i + 1][j - 1] : 0;
    sum += isValidIndex(i + 1, j, num_rows, num_cols) ? array[i + 1][j] : 0;
    sum += isValidIndex(i + 1, j + 1, num_rows, num_cols) ? array[i + 1][j + 1] : 0;
    sum += isValidIndex(i, j + 1, num_rows, num_cols) ? array[i][j + 1] : 0;
    sum += isValidIndex(i - 1, j + 1, num_rows, num_cols) ? array[i - 1][j + 1] : 0;
    sum += isValidIndex(i - 1, j, num_rows, num_cols) ? array[i - 1][j] : 0;
    //return sum;

    // optimized 
    int rowOffset[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int colOffset[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int curr_sum = 0;
    for (int c = 0; c < 8; c++) {
        int adjX = i + rowOffset[c];
        int adjY = j + colOffset[c];
        int val = isValidIndex(adjX, adjY, num_rows, num_cols) ? array[adjX][adjY] : 0;
        curr_sum = curr_sum + val;
    }
    return curr_sum;
}


int main() {
    int arr[5][5] = {
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 10, -1, 1 },
        { 1, 1, 2, 1, -2 },
        { 1, 1, -1, 1, -10 }
    };

    int x = 3;
    int y = 3;
    cout << adj_sum(arr, 5, 5, x, y) << endl;
    x = 0;
    y = 0;
    cout << adj_sum(arr, 5, 5, x, y) << endl;
    return 0;

}