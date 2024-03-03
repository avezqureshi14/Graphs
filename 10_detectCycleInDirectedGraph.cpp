#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, int n, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
    }
}

void indegreeOfGraph(unordered_map<int, set<int>> &adjList, vector<int> &indegree)
{
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
}

bool topoSort(unordered_map<int, set<int>> &adjList, int n, vector<int> &indegree)
{
    queue<int> q;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;
        for (auto i : adjList[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (count == n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool detectCycle(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> indegree(n);
    prepareAdjList(adjList, n, edges);
    indegreeOfGraph(adjList, indegree);
    return topoSort(adjList, n, indegree);
}

int main()
{
    int n = 6;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(3, 5));

    if (detectCycle(n, edges))
    {
        cout << "Yeah! Cycle is  Present" << endl;
    }
    else
    {
        cout << "Nope! Cycle is not Present" << endl;
    }
    return 0;
}