/*
    https://www.geeksforgeeks.org/the-celebrity-problem/
    Author : Abhijeet Kandalkar
    LinkedIn : https://www.linkedin.com/in/abhijeetkandalkar/
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int searchCelebrity(vector<vector<int>>& vec) {
    stack<int> s;
    for (int i = 0; i < vec.size(); i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if (vec[A][B]) {
            s.push(B);
        }
        else {
            s.push(A);
        }
    }

    int celeb = s.top();
    s.pop();

    for (int i = 0; i < vec.size(); i++) {
        if ((i != celeb) && (vec[celeb][i] || !vec[i][celeb]))
            return -1;
    }
    return celeb;
}

int main() {
    vector<vector<int>> vec = {
        { 1, 0, 1, 0 },
        { 0, 1, 1, 1 },
        { 0, 0, 0, 0 },
        { 1, 0, 1, 1 }
    };

    cout << searchCelebrity(vec) << endl;
    return 0;
}
