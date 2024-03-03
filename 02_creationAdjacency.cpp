#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>&edges){
    vector<int>ans[n];
    for (int i = 0; i < m; i++)
    { 
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>>adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
        
    }
    return adj;
    
}

int main()
{
    //number of nodes
    int n = 3;

    //number of edges
    int m = 2;

    vector<vector<int>>edges = {{2,1},{2,0}};

    for(auto i : printAdjacency(n,m,edges)){
        for(auto j : i){
            cout<<j<<" ";
        }

    }
    return 0;
}