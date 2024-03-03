#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool isCyclicDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node, int parent)
{
    visited[node] = 1;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(adjList, visited, i, node);
            if (ans == true)
            {
                return true;
            }
        }
        else if (i != parent)
        {
            return true;
        }
    }

    return false;
}
string CycleDetection(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(adjList, visited, i, -1);
            if (ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(4, 0));
    string s = CycleDetection(6, edges);
    cout << s;

    return 0;
}