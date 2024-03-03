#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<pair<int, int>>> &adjList, vector<pair<int, pair<int, int>>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second.first;
        int weight = edges[i].second.second;
        adjList[u].insert({v, weight});
    }
}

void topoSort(unordered_map<int, set<pair<int, int>>> &adjList, unordered_map<int, bool> &visited, stack<int> &stk, int node)
{
    visited[node] = true;
    for (auto i : adjList[node])
    {
        if (visited[i.first] == false)
        {
            topoSort(adjList, visited, stk, i.first);
        }
    }

    stk.push(node);
}

void findShortestPath(vector<int> &dest, unordered_map<int, set<pair<int, int>>> &adjList, stack<int> &stk, int src)
{
    dest[src] = 0;

    while (!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        if (dest[top] != INT_MAX)
        {
            for (auto i : adjList[top])
            {
                if (dest[top] + i.second < dest[i.first])
                {
                    dest[i.first] = dest[top] + i.second;
                }
            }
        }
    }
}

vector<int> shortestPathOfDirectedGraph(int vertex, vector<pair<int, pair<int, int>>> &edges, int src)
{
    unordered_map<int, set<pair<int, int>>> adjList;
    unordered_map<int, bool> visited;
    stack<int> stk;
    vector<int> dest(vertex, INT_MAX);
    prepareAdjList(adjList, edges);
    for (int i = 0; i < vertex; i++)
    {
        topoSort(adjList, visited, stk, i);
    }
    findShortestPath(dest, adjList, stk, src);
    return dest;
}

int main()
{
    vector<pair<int, pair<int, int>>> edges;
    edges.push_back({0, {1, 5}});
    edges.push_back({0, {2, 3}});
    edges.push_back({1, {2, 2}});
    edges.push_back({1, {3, 6}});
    edges.push_back({2, {3, 7}});
    edges.push_back({2, {4, 4}});
    edges.push_back({2, {5, 2}});
    edges.push_back({3, {4, -1}});
    edges.push_back({4, {5, -2}});
    int vertex = 6;
    for (auto i : shortestPathOfDirectedGraph(vertex, edges, 1))
    {
        cout << i << " ";
    }
    return 0;
}