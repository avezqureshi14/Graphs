#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// topological sort using BFS is known as Kahn's Algorithm

void prepareAdjacency(unordered_map<int, set<int>> &adjList, int n, vector<pair<int, int>> &edges)
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

void topoSort(unordered_map<int, set<int>> &adjList, vector<int> &indegree, vector<int> &ans, int n)
{

    // push 0 degree element inside the queue

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // store ans
        ans.push_back(front);

        // no break the legs of i connected peoples
        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
}

vector<int> topoLogicalSort(vector<pair<int, int>> &edges, int n)
{
    unordered_map<int, set<int>> adjList;

    //why it was define here 
    vector<int> indegree(n);
    //and when we are defining here it is adding extra 0s and after that our numbers are getting placed
    vector<int> ans;
    prepareAdjacency(adjList, n, edges);
    indegreeOfGraph(adjList, indegree);
    topoSort(adjList, indegree, ans, n);

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

    for (auto i : topoLogicalSort(edges, n))
    {
        cout << i << " ";
    }

    return 0;
}