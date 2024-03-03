#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjacency(unordered_map<int, set<int>> &adjList, int n, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
    }
}

void printAdj(unordered_map<int, set<int>> &adjList, int n)
{
    for (auto i : adjList)
    {
        cout << i.first << " -> ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

// kitne baar koi element kisika adjacent hai isse kehte indegree of graph (apne pass kitne log(simple basha meh))
vector<int> indegreeOfGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    prepareAdjacency(adjList, n, edges);
    vector<int> indegree(n);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
        cout << endl;
    }
    return indegree;
}

int main()
{
    int n = 4;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(3, 2));

    for (auto i : indegreeOfGraph(n, edges))
    {
        cout << i << " ";
    }

    return 0;
}