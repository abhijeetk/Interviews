/*
Imagine that you have a knapsack which can carry a certain
maximum amount of weight and you have a set of items with
their own weight and a monetary value. You are going to to sell
your items in the market but you can only carry what fits in the
knapsack. How do you maximize the amount of money that you
can earn?

Or more formally…

Given a list of items with values and weights, as well as a max
weight, find the maximum value you can generate from items,
where the sum of the weights is less than or equal to the max.

eg.
items = {(w:2, v:6), (w:2, v:10), (w:3, v:12)}
max weight = 5
knapsack(items, max weight) = 22
*/

/*
This can be done by recursively iterating over all the items. If
the item isn’t too heavy to fill the remaining space in the bag,
we recursively compute the max value of both, including and
not including the current item. If it is too heavy, our only option
is to not include it and to continue on to the next item
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item{
public :
    int weight;
    int profit;
    Item(int w = 0, int p = 0) {
        weight = w;
        profit = p;
    }
};

int knaSack(int remaining, vector<Item>& items, int chance) {
    if (chance >= items.size())
        return 0;

    Item i = items[chance];
    if (i.weight > remaining)
        return knaSack(remaining, items, chance + 1);

    int currMax = max(
        knaSack(remaining - i.weight, items, chance + 1) + i.profit,
        knaSack(remaining, items, chance + 1)
    );
    return currMax;
}

int knapSack(vector<Item>& items, int maxWeight) {
    if (items.empty())
        return 0;

    return knaSack(maxWeight, items, 0);
}

int knaSackDP1(int remaining, vector<Item>& items, int chance, vector<vector<int>>& cache) {
    if (chance >= items.size())
        return 0;

    if (cache[chance][remaining] != -1) {
        cout << "cache hit" << endl;
        return cache[chance][remaining];
    }

    Item i = items[chance];
    int currMax;
    if (i.weight > remaining)
        currMax = knaSack(remaining, items, chance + 1);
    else {
        currMax = max(
            knaSack(remaining - i.weight, items, chance + 1) + i.profit,
            knaSack(remaining, items, chance + 1)
        );
    }
    cache[chance][remaining] = currMax;
    return currMax;
}

// Using 2D array to cache result.
// cache[index][weight] = profit
int knapSackDP1(vector<Item>& items, int maxWeight) {
    if (items.empty())
        return 0;

    vector<vector<int>> cache;
    cache.resize(items.size());
    for (int i = 0; i < items.size(); i++) {
        cache[i].resize(maxWeight+1);
    }

    for (int i = 0; i < cache.size(); i++) {
        for (int j = 0; j < cache[0].size(); j++) {
            cache[i][j] = -1;
        }
        cout << endl;
    }
    int res = knaSackDP1(maxWeight, items, 0, cache);

#if 0
    cout << "[START] DP : TABLE" << endl;
    for (int i = 0; i < cache.size(); i++) {
        for (int j = 0; j < cache[0].size(); j++) {
            cout << cache[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "[END] DP : TABLE" << endl;
#endif
    return res;
}


int knaSackDPBottomUp(int remaining, vector<Item>& items, int chance, vector<vector<int>>& cache) {
    // map index of cache with index of below loops
    // cache-row = 4 & cache-col = 6
    // items = 3 & remaining = 5 hence <= to make ranges equal to length of cache-row and cache-col
    for (int w = 1; w <= remaining; w++) {
        for (int i = 1; i <= items.size(); i++) {
            int itemWeight = items[i-1].weight; // align to actual index in items
            int itemProfit = items[i-1].profit;
            if (itemWeight > w) {
                cache[i][w] = cache[i - 1][w];
            }
            else {
                cache[i][w] = max(
                    cache[i - 1][w-itemWeight] + itemProfit,  // include
                    cache[i - 1][w] //exclude
                );
            }
        }
    }
    return cache[items.size() - 1][remaining];
}

// Using 2D array to cache result.
// cache[index][weight] = profit
int knapSackDPBottomUp(vector<Item>& items, int maxWeight) {
    if (items.empty())
        return 0;

    vector<vector<int>> cache;
    cache.resize(items.size()+1);
    for (int i = 0; i < items.size()+1; i++) {
        cache[i].resize(maxWeight + 1);
    }

    for (int i = 0; i < cache.size(); i++) { // index
        for (int j = 0; j < cache[0].size(); j++) { // weight
            cout << "i : " << i << " j : " << j << endl;
            if (j == 0 || i == 0) {
                cache[i][j] = 0;
            }
            else {
                cache[i][j] = -1;
            }

        }
    }
    int res = knaSackDPBottomUp(maxWeight, items, 0, cache);

    cout << "[START]" << endl;
    for (int i = 0; i < cache.size(); i++) {
        for (int j = 0; j < cache[0].size(); j++) {
            cout << cache[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "[END]" << endl;
    return res;
}
int main() {
    vector<Item> items;
    items.emplace_back(2, 6);
    items.emplace_back(2, 10);
    items.emplace_back(3, 12);
    cout << knapSack(items, 5) << endl;
    cout << knapSackDP1(items, 5) << endl;
    cout << knapSackDPBottomUp(items, 5) << endl;
    return 0;
}
