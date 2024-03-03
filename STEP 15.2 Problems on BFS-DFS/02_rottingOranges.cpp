#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    //row
    int n = grid.size();
    //col
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0)); // Initialize visited vector

    queue<pair<pair<int, int>, int>> q;

    int freshOranges = 0; // To keep track of fresh oranges

    // Enqueue all rotten oranges and count fresh oranges
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
            else if (grid[i][j] == 1)
            {
                freshOranges++;
            }
        }
    }

    int tm = 0;
    //t r b l
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            // next row wise neighbour
            int nrow = r + drow[i];
            // next col wise neighbour
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                visited[nrow][ncol] = 2;
                freshOranges--;
            }
        }
    }

    if (freshOranges == 0)
    {
        return tm;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid);
    return 0;
}
