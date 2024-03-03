#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepAdjList(unordered_map<int, set<int>> &adjList, int n, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &parent, int n, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adjList[front])
        {
            if (visited[i] == false)
            {
                parent[i] = front;
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

//bfs se parent ka array banao 
//fir destination se source tak traverse karo

vector<int> shortestPathInUnDirectedGraphs(int n, vector<pair<int, int>> &edges, int s, int d)
{
    vector<int> ans;
    vector<int> parent(n);
    unordered_map<int, bool> visited;
    unordered_map<int, set<int>> adjList;
    prepAdjList(adjList, n, edges);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            bfs(adjList, visited, parent, n, i);
        }
    }
    int currentNode = d;
    ans.push_back(currentNode);
    while (currentNode != s)
    {
        //current node , current node ka parent rahega
        currentNode = parent[currentNode];
        ans.push_back(currentNode); //this need to be done here only 
    }
    cout<<endl;
    for(auto i : parent){
        cout<<i<<" ";
    }
    cout<<endl;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 8;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(1, 4));
    edges.push_back(make_pair(2, 5));
    edges.push_back(make_pair(5, 8));
    edges.push_back(make_pair(3, 8));
    edges.push_back(make_pair(4, 6));
    edges.push_back(make_pair(6, 7));
    edges.push_back(make_pair(7, 8));
    int s = 1;
    int d = 8;
    for (auto i : shortestPathInUnDirectedGraphs(n, edges, s, d))
    {
        cout << i << " ";
    }

    return 0;
}
