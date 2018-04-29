/*
Given an integer representing a given amount of change, write a
function to compute the minimum number of coins required to make
that amount of change. You can assume that there is always a
1¢ coin.
eg. (assuming American coins: 1, 5, 10, and 25 cents)
makeChange(1) = 1 (1)
makeChange(6) = 2 (5 + 1)
makeChange(49) = 7 (25 + 10 + 10 + 1 + 1 + 1 + 1)
*/
#include <iostream>
#include <vector>
using namespace std;

int makeChange(int sum, vector<int>& coins) {
    if (sum == 0)
        return 0;

    int minCoins = INT_MAX;
    for (int c : coins) {
        if (sum - c >= 0) {
            int currentMin = makeChange(sum - c, coins);
            if (currentMin < minCoins)
                minCoins = currentMin;
        }
    }

    //cout << "sum : " << sum << "\t" << " minCoins : " << 1+minCoins << endl;
    return 1 + minCoins;
}

int makeChangeDP(int sum, vector<int>& coins, vector<int>& cache) {
    if (cache[sum] != -1)
        return cache[sum];

    int minCoins = INT_MAX;
    for (int c : coins) {
        if (sum - c >= 0) {
            int currentMin = makeChangeDP(sum - c, coins, cache);
            if (currentMin < minCoins)
                minCoins = currentMin;
        }
    }

    //cout << "sum : " << sum << "\t" << " minCoins : " << 1 + minCoins << endl;
    cache[sum] = 1 + minCoins;
    return 1 + minCoins;
}

int makeChangeDPUtil(int sum, vector<int>& coins) {
    if (coins.empty())
        return 0;

    vector<int> cache(sum+1, -1);
    cache[0] = 0;
    return makeChangeDP(sum, coins, cache);
}

int makeChangeDPBottomUp(int sum, vector<int>& coins, vector<int>& cache) {
    for (int i = 1; i <= sum; i++) {
        int minCoins = INT_MAX;
        for (int c : coins) {
            int currentMin = -1;
            if (i - c >= 0) {
                currentMin = cache[i-c];
                if (currentMin < minCoins) {
                    minCoins = currentMin;
                }
            }
        }
        cache[i] = 1 + minCoins;
    }
    return cache[sum];
}

int makeChangeDPBottomUpUtil(int sum, vector<int>& coins) {
    if (coins.empty())
        return 0;

    vector<int> cache(sum + 1, -1);
    cache[0] = 0;
    return makeChangeDPBottomUp(sum, coins, cache);
}

int main() {
    vector<int> coins = { 1, 5, 10, 25 };
    int sum = 1;
    cout << makeChange(sum, coins) << endl;
    sum = 6;
    cout << makeChange(sum, coins) << endl;
    sum = 49;
    cout << makeChangeDPBottomUpUtil(sum, coins) << endl;
    coins.clear();
    sum = 12;
    coins = {10, 6, 1};
    cout << makeChangeDPUtil(sum, coins) << endl; // 2 => {6, 6}
    cout << makeChangeDPBottomUpUtil(sum, coins) << endl;
    return 0;
}