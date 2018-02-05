/*
Instructions:
Given an empty chessboard (8x8 grid), a knight is placed on one of the squares.
The knight 'K' at position (3, 3) and its possible movements 'X' are shown in
the example below:
    * * * * * * * *
    * * X * X * * *
    * X * * * X * *
    * * * K * * * *
    * X * * * X * *
    * * X * X * * *
    * * * * * * * *
    * * * * * * * *
Depending on the knight's position on the board, 0-6 of the 8 possible movements
may cause the knight to leave the chess board. If the knight moves n times,
each time choosing one of the 8 possible moves uniformly at random, determine the
probability that the knight is still on the board after making n random moves.
After the knight has left the board, it may not reenter.
Please implement the method probability which given a start position x, y, and
a number of moves n, returns the probability a knight remains on the board as
described above.
*/
#include <vector>
#include <iostream>
using namespace std;

double probability(int x, int y, int n) {
    if (n == 0)
        return 1.0;

    int boardSize = 8; // Define an 8x8 grid
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

    // Set the starting position 
    board[x][y] = 1.0;

    // Possible moves
    int moves[8][2] = {
        { -2, -1 },
        { -2, 1 },
        { 2, -1 },
        { 2, 1 },
        { -1, -2 },
        { -1, 2 },
        { 1, -2 },
        { 1, 2 },
    };

    double count = 0.0;
    for (int i = 0; i < n; i++) {
        for (int m = 0; m < 8; m++) {
            int row = x + moves[m][0];
            int col = y + moves[m][1];
            if (row < 8 && col < 8 && row >= 0 && col >= 0) {
                count++;
            }
        }
    }
    return count * (1.0 / 8.0);
}

int main() {
    cout << probability(0, 0, 0) << endl;
    cout << probability(3, 3, 1) << endl;
    cout << probability(0, 0, 1) << endl;
    return 0;
}