#include <iostream>
#include <algorithm>

/*
https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/#comment-3321908697

Given an array of integers where each element represents the max number of 
steps that can be made forward from that element. Write a function to return
the minimum number of jumps to reach the end of the array
(starting from the first element). If an element is 0,
then cannot move through that element.

Example:
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)

First element is 1, so can only go to 3. Second element is 3, so can make at most 3 steps eg to 5 or 8 or 9.
*/
#include <iostream>
#include <vector>
using namespace std;

int minJump(vector<int>& arr) {
    if (arr.empty())
        return INT_MAX;

    if (arr[0] == 0) // If first element is 0, we can not move further
        return INT_MAX;

    vector<int> dp(arr.size(), INT_MAX);
    dp[0] = 0;
    // Minimum number of steps to reach to position i,
    // is equal to number of steps through any j varies from 0, i-1
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (j + arr[j] >= i && dp[j] != INT_MAX) {
                // Minimum of
                // 1. current value
                // 2. position from which we are coming + 1
                dp[i] = std::min(dp[i], dp[j] + 1);  
            }
        }
    }
    return dp[arr.size() - 1];
}

int main() {
    vector<int> vec = {1, 0, 1, 0};
    cout << minJump(vec) << endl;
    return 0;
}