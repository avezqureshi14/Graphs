#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    // col
    int m = image[0].size();
    // row
    int n = image.size();
    int initialClr = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
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
            // cout<<"{ "<<nrow<<" , "<<ncol<<" }";
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && image[nrow][ncol] == initialClr)
            {
                image[nrow][ncol] = color;
                q.push({nrow, ncol});
            }
        }
        cout<<endl;
    }

    return image;
}
int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    for (auto i : floodFill(image, sr, sc, color))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}