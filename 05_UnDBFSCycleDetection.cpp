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
        adjList[v].insert(u);
    }
}
// agar apne frontnode ka daddy i nahi hai aur koi dusra hai toh johl hai(cycle present) and visited bhi hai
bool isCyclic(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, int node)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto i : adjList[frontNode])
        {
            if (visited[i] == 1 && i != parent[frontNode])
            {
                return true;
            }
            else if (visited[i] == 0) // dont forget this point
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }

    return false;
}

bool cycleDetection(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    prepareAdjList(adjList, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            if (isCyclic(adjList, visited, i))
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(5, 4));
    if (cycleDetection(6, edges))
    {
        cout << "Cycle is Present " << endl;
    }
    else
    {
        cout << "Cycle is not Present " << endl;
    }
    return 0;
}