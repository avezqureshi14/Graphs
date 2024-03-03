#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Works only on DAG if there is cycle present in our graph we cannot find Topological Sort

void prepareAdjList(vector<pair<int, int>> &edges, int n, unordered_map<int, set<int>> &adjList)
{
    for (int i = 0; i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
    }
}

void topoSort(int n, unordered_map<int, set<int>> &adjList, vector<bool> &visited, stack<int> &stk, int node)
{
    //just simple recursive calls
    visited[node] = 1;
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            topoSort(n, adjList, visited, stk, i);

        }
    }
    //when returning back from recursive calls just go on adding elements into stack
    stk.push(node);
}

vector<int> topoLogicalSort(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    //this initialization is very much important 
    vector<bool> visited(n, false);
    vector<int> ans;
    stack<int> stk;
    prepareAdjList(edges, n, adjList);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSort(n, adjList, visited, stk, i);
        }
    } 

    while (!stk.empty())
    {
        ans.push_back(stk.top()) ;
        stk.pop();
    }

    return ans;
}

int main()
{
    int n = 4;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(3, 2));

    for(auto i : topoLogicalSort(n,edges)){
        cout<<i<<" ";
    }
    return 0;
}