#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, set<int>> &adjList, vector<bool> &visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adjList[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    unordered_map<int, set<int>> adjList;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && j != i)
            {
                adjList[i].insert(j);
            }
        }
    }
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, i);
            count++;
        }
    }
    for (auto i : adjList)
    {
        cout << i.first << ": ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return count;
}

int main()
{
    vector<vector<int>> adj = {{1, 0, 0, 0, 0, 1, 1}, {0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 1, 1}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0}, {1, 0, 1, 0, 0, 1, 1}, {1, 0, 1, 0, 0, 1, 1}};
    int V = 7;
    cout << numProvinces(adj, V);
    return 0;
}