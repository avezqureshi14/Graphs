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

void dfs(unordered_map<int, set<int>> &adjList,unordered_map<int, bool> &visited,vector<int> &ans,int node){
    ans.push_back(node);
    visited[node] = 1;
    for(auto i : adjList[node]){
        if (visited[i] == 0)
        {
            dfs(adjList,visited,ans,i);
            visited[i] = 1;
        }
    }
}

vector<int> DFS(int vertex, vector<pair<int, int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;
    prepareAdjList(adjList,edges);

    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == 0)
        {
            dfs(adjList,visited,ans,i);
        }
        
    }

    return ans;
    
}
int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(1, 4));
    for (auto i : DFS(5, edges))
    {
        cout << i << " ";
    }
    return 0;
}