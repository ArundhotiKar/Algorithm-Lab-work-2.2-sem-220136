#include <bits/stdc++.h>
using namespace std;

#define N 4 // N x N চেসবোর্ড

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) 
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--) 
        if (board[i][j]) return false;

    return true;
}

bool solveNQueen(int board[N][N], int col) {
    if (col >= N) return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueen(board, col + 1)) return true;

            board[i][col] = 0; 
        }
    }
    return false;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cout << (board[i][j] ? "Q " : ". ");
        cout << "\n";
    }
}

int main() {
    int board[N][N] = {0};

    if (solveNQueen(board, 0))
        printSolution(board);
    else
        cout << "No solution exists\n";

    return 0;
}
