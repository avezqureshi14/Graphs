#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    for (auto i : adjList[node])
    {
        if (i == parent)
        {
            continue;
        }
        if (!visited[i])
        {
            dfs(i, node, timer, disc, low, result, adjList, visited); 
            low[node] = min(low[node], low[i]);
            if (low[i] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(i);
                result.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[i]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int vertex, int e)
{
    // adjlist
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> result;
    int timer = 0;
    vector<int> disc(vertex);
    vector<int> low(vertex);
    int parent = -1;
    unordered_map<int, bool> visited;
    for (int i = 0; i < vertex; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for (int i = 0; i < vertex; i++)
    {
        dfs(i, parent, timer, disc, low, result, adjList, visited);
    }
}
int main()
{

    return 0;
}