#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<char>> &board)
{
    // row
    int n = board.size();
    // col
    int m = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'X')
            {
                q.push({i, j});
            }
        }
    }
    // t r b l
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 1 && nrow < n - 1 && ncol >= 1 && ncol < m - 1 && board[nrow][ncol] == 'O')
            {
                board[nrow][ncol] = 'X';
                q.push({nrow, ncol});
            }
        }
    }
    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void solveII(vector<vector<char>> &board)
{
    // row
    int n = board.size();
    // col
    int m = board[0].size();
    for (int col = 1; col < m - 1; col++)
    {
        for (int row = 1; row < n - 1; row++)
        {
            int tp = board[row - 1][col];
            int bt = board[row + 1][col];
            int lt = board[row][col - 1];
            int rt = board[row][col + 1];
            if(tp == 'X' && bt == 'X' && lt == 'X' && rt == 'X'){
                board[row][col] = 'X';
            }
        }
    }
}
 
int main()
{
    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board = {{'X'}};
    solve(board);
    return 0;
}