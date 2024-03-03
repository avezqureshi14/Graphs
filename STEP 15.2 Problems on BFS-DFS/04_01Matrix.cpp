#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    // row
    int n = mat.size();
    // col
    int m = mat[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> ans(n, vector<int>(m, 0));
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // t r b l
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1 && visited[nrow][ncol] != 1)
            {
                ans[nrow][ncol] = d + 1;
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, d + 1});
            }
        }
    }
    return ans;
}
int main()
{
    // vector<vector<int>>mat = {{0,0,0},{0,0,0},{0,0,0}};
    vector<vector<int>> mat = {{0, 0, 0}}; 
    for (auto i : updateMatrix(mat))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}