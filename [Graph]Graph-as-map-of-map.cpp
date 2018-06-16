/*
Leetcode : 399
Problem:
Equations are given in the format A / B = k, where A and B are variables represented
as strings, and k is a real number (floating point number).
Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values,
vector<pair<string, string>> queries , where equations.size() == values.size(),
and the values are positive. This represents the equations. Return vector<double>.

According to the example above:
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result
in no division by zero and there is no contradiction.
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef unordered_map<string, unordered_map<string, double>> graph;
class Solution {
public :
    vector<double> calcEquation(const vector<pair<string, string>> equations,
        vector<double> values,
        const vector<pair<string, string>>& queries) {


        int len = equations.size();
        graph g;
        for (int i = 0; i < len; i++) {
            string x = equations[i].first;
            string y = equations[i].second;
            double val = values[i];

            g[x][y] = val;
            g[y][x] = 1.0 / val;
        }

        len = queries.size();
        vector<double> ans;

        for (int i = 0; i < len; i++) {
            string src = queries[i].first;
            string dest = queries[i].second;
            unordered_set<string> visited;
            ans.push_back(dfs(g, src, dest, visited));
            cout << i << " : " << ans[i] << endl;
        }
        return ans;
    }

private :
    double dfs(graph& g, string src, string dest, unordered_set<string>& visited) {
        float distance = 0.0;
        visited.insert(src);
        if (src == dest)
            return 1.0;

        for (auto node : g[src]) {
            string intermidiateSrc = node.first;
            double val = node.second;
            if (visited.count(intermidiateSrc) > 0)
                continue;

            double intermediateVal = dfs(g, intermidiateSrc, dest, visited);
            double res = 1.0;
            if (intermediateVal > 0) {
                res = intermediateVal * g[src][intermidiateSrc];
                return res;
            }
        }
        return -1.0;
    }

};
int main() {
    Solution s;
    const vector<pair<string, string>> equations = { { "a", "b" },{ "c", "a" } };
    vector<double> values = { 2.0, 3.0 };
    const vector<pair<string, string>>& queries = { { "a", "c" },{ "b", "a" } };
    //a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
    vector<double> ans = s.calcEquation(equations, values, queries);
    return 0;
}