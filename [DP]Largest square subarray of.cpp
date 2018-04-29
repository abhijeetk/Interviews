/*
Given a 2D boolean array, find the largest square subarray of
true values. The return value should be the side length of the
largest square subarray subarray.

eg.
arr = [
    [FALSE, TRUE, FALSE, FALSE],
    [TRUE,  TRUE, TRUE,  TRUE ],
    [FALSE, TRUE, TRUE,  FALSE]
]
squareSubmatrix(arr) = 2
First solution
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int squareSubmatrix(vector<vector<bool>>& arr, int i, int j) {
    if (i == arr.size() || j == arr[0].size())
        return 0;

    if (arr[i][j]) {
        return(1 + std::min(std::min(
            squareSubmatrix(arr, i + 1, j),
            squareSubmatrix(arr, i, j + 1)),
            squareSubmatrix(arr, i + 1, j + 1)
        ));
    }
    return 0;
}

int squareSubmatrix(vector<vector<bool>>& arr) {
    /* 
    What is the biggest square subarray for which the 
    current cell is the upper left-hand corner?
    */
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j]) {
                int currMax = squareSubmatrix(arr, i, j);
                if (currMax > max)
                    max = currMax;
            }
        }
    }
    return max;
}

int squareSubmatrixDP(vector<vector<bool>>& arr, int i, int j, vector<vector<int>>& cache) {
    if (i == arr.size() || j == arr[0].size())
        return 0;

    if (arr[i][j]) {
        if (cache[i][j] > 0)
            return cache[i][j];

        int currVal = (1 + std::min(std::min(
            squareSubmatrix(arr, i + 1, j),
            squareSubmatrix(arr, i, j + 1)),
            squareSubmatrix(arr, i + 1, j + 1)
        ));
        cache[i][j] = currVal;
        return cache[i][j];
    }
    return 0;
}

int squareSubmatrixDP(vector<vector<bool>>& arr) {
    /*
    What is the biggest square subarray for which the
    current cell is the upper left-hand corner?
    */
    vector<vector<int>> cache;
    cache.resize(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        cache[i].resize(arr[0].size());
        //for (int j = 0; j < arr[0].size(); j++) {
        //    if (arr[i][j])
        //        cache[i][j] = 1;
        //    else
        //        cache[i][j] = 0;
        //}
    }

    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j]) {
                int currMax = squareSubmatrixDP(arr, i, j, cache);
                if (currMax > max)
                    max = currMax;
            }
        }
    }
    return max;
}

int squareSubmatrixDPBottomUp(vector<vector<bool>>& arr, int i, int j, vector<vector<int>>& cache) {
    if (i == arr.size() || j == arr[0].size())
        return 0;

    if (arr[i][j]) {
        if (cache[i][j] > 0)
            return cache[i][j];

        int currVal = (1 + std::min(std::min(
            squareSubmatrix(arr, i + 1, j),
            squareSubmatrix(arr, i, j + 1)),
            squareSubmatrix(arr, i + 1, j + 1)
        ));
        cache[i][j] = currVal;
        return cache[i][j];
    }
    return 0;
}

int squareSubmatrixDPBottomUp(vector<vector<bool>>& arr) {
    /*
    What is the biggest square subarray for which the
    current cell is the bottom-right hand corner?
    */
    vector<vector<int>> cache;
    cache.resize(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        cache[i].resize(arr[0].size());
    }

    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (i == 0 || j == 0) {
                cache[i][j] = arr[i][j] ? 1 : 0;
            }
            else {
                if (arr[i][j]) {
                    cache[i][j] = 1 + std::min(std::min(
                        cache[i - 1][j],
                        cache[i][j - 1]),
                        cache[i - 1][j - 1]
                    );

                    if (max < cache[i][j])
                        max = cache[i][j];
                }
            }
        }
    }
    return max;
}

int main() {
    vector<vector<bool>> arr = {
        {false, true, false, false  },
        {true,  true, true, true    },
        {false, true, true, false   }
    };

    cout << squareSubmatrix(arr) << endl;
    cout << squareSubmatrixDP(arr) << endl;
    cout << squareSubmatrixDPBottomUp(arr) << endl;

    vector<vector<bool>> arr1 = {
        { true, true, true, true, true },
        { true,  true, true, true, false },
        { true,  true, true, true, false },
        { true,  true, true, true, false },
        { true,  false, false, false, false },
    };

    cout << squareSubmatrix(arr1) << endl;
    cout << squareSubmatrixDP(arr1) << endl;
    cout << squareSubmatrixDPBottomUp(arr1) << endl;
    return 0;
}