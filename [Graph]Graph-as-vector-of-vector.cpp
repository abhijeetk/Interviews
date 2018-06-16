//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    bool canVisitAllRooms(vector<vector<int>>& rooms) {
//        unordered_set<int> visited;
//        dfs(rooms, 0, visited);
//        return visited.size() == rooms.size();
//    }
//private:
//    void dfs(const vector<vector<int>>& rooms,
//        int cur, unordered_set<int>& visited) {
//        if (visited.count(cur)) return;
//        visited.insert(cur);
//        for (int nxt : rooms[cur])
//            dfs(rooms, nxt, visited);
//    }
//};
//
//int main() {
//    vector<vector<int>> adj = {
//        {1,3},
//        {3,0,1},
//        {2},
//        {0}
//    };
//
//    Solution s;
//    s.canVisitAllRooms(adj);
//
//
//
//}