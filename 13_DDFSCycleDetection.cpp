#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
    }
}

bool dfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, int node)
{
    visited[node] = 1;
    dfsVisited[node] = 1;
    for (auto i : adjList[node])
    {
        if (visited[i] == 0)
        {
            bool ans = dfs(adjList, visited, dfsVisited, i);
            if (ans)
            {
                return true;
            }
        }
        else if (dfsVisited[i] == 1)
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

bool isCyclePresent(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    prepareAdjList(adjList, edges);
    for (int i = 1; i <= vertex; i++)
    {
        if (visited[i] == 0)
        {
            return dfs(adjList, visited, dfsVisited, i);
        }
    }
    return false;
}

int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(4, 5));
    edges.push_back(make_pair(5, 6));
    edges.push_back(make_pair(6, 4));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(3, 7));
    edges.push_back(make_pair(7, 4));
    if (isCyclePresent(7, edges))
    {
        cout << "Cycle is Present " << endl;
    }
    else
    {
        cout << "Cycle is not Present " << endl;
    }
    return 0;
}