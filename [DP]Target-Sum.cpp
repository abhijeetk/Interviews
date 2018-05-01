/*
Given an array of integers 'nums' and a target value 'T', find the
number of ways that you can add and subtract the values in
nums to add up to T.
eg.
nums = {1, 1, 1, 1, 1}
T = 3
targetSum(nums, T) = 5

1 + 1 + 1 + 1 - 1
1 + 1 + 1 - 1 + 1
1 + 1 - 1 + 1 + 1
1 - 1 + 1 + 1 + 1
-1 + 1 + 1 + 1 + 1

*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int targetSumUtil(vector<int>& nums, int T, int depth, int sum) {

    if (depth == nums.size())
        if (sum == T)
            return 1;
        else
            return 0;

    int res = targetSumUtil(nums, T, depth + 1, sum + nums[depth]) +
        targetSumUtil(nums, T, depth + 1, sum - nums[depth]);

    return res;

}

int targetSum(vector<int>nums, int T) {
    if (nums.empty())
        return 0;

    int res = targetSumUtil(nums, T, 0, 0);
    return res;
}

int targetSumUtilDP(vector<int>& nums, int T, int depth, int sum, map<int, map<int, int>>& m) {

    if (depth == nums.size())
        if (sum == T)
            return 1;
        else
            return 0;

    auto itr = m.find(depth);
    if (itr != m.end()) {
        auto it = m[depth].find(sum);
        if (it != m[depth].end()) {
            cout << "Hit : [" << depth << " : " << sum << "]\t" << m[depth][sum] << endl;
            return m[depth][sum];
        }
    }

    int res = targetSumUtilDP(nums, T, depth + 1, sum + nums[depth], m) +
        targetSumUtilDP(nums, T, depth + 1, sum - nums[depth], m);

    m[depth][sum] = res;
    return res;

}

int targetSumDP(vector<int>nums, int T) {
    if (nums.empty())
        return 0;

    map<int, map<int, int>> cache;

    int res = targetSumUtilDP(nums, T, 0, 0, cache);
    return res;
}

int main() {
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int T = 3;
    cout << targetSum(nums, T) << endl;
    cout << targetSumDP(nums, T) << endl;
    return 0;
}