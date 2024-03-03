#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<pair<int, int>>> &adjList, vector<pair<pair<int, int>, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &edges, int src)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    prepareAdjList(adjList, edges);

    // we are initialising each from n+1 because our nodes starts from 1
    vector<int> dist(n + 1); // n = no. of vertices
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // let's start the ALGO
    dist[src] = 0;
    parent[src] = -1;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        // find min wali node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && dist[v] < mini)
            {
                u = v;
                mini = dist[v];
            }
        }
        // mark min node as true
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < dist[v])
            {
                parent[v] = u;
                dist[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) // our nodes starts from 1 and if we start loop from 1 then it has parent of -1 that's why we are starting loop from 2
    {
        result.push_back({{parent[i], i}, dist[i]});
    }
    return result;
}

int main()
{
    int n = 5;   // Number of vertices
    int m = 7;   // Number of edges
    int src = 1; // Source vertex

    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 2},
        {{1, 3}, 4},
        {{2, 3}, 1},
        {{2, 4}, 7},
        {{3, 4}, 3},
        {{3, 5}, 2},
        {{4, 5}, 5}};

    vector<pair<pair<int, int>, int>> result = calculatePrimsMST(n, m, edges, src);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (const auto &edge : result)
    {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }
}