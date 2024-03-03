#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>dijkstra(vector<vector<int>>&vec, int vertices, int edges, int source){
    //create adjancecy list
    unordered_map<int,list<pair<int,int>>>adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int>dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    
    set<pair<int,int>>st;

    dist[source] = 0;
    //distance -> node //mapping
    //i.second = distance -> i.first = node
    st.insert({0,source});
    while (!st.empty())
    {
        //fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record now
        st.erase(st.begin());

        //traverse on neighbours
        for(auto  i : adj[topNode]){
            if (nodeDistance + i.second < dist[i.first])
            {
                auto record = st.find({dist[i.first],i.first});
                //if record found then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                //distance update
                dist[i.first] = nodeDistance + i.second;
                //record push in set
                st.insert({dist[i.first],i.first});
            }
        } 
    }
    return dist;    
}
int main()
{
    int vertices = 5;
    int edges = 7;
    int source = 0;

    vector<vector<int>> vec = {
        {2, 0, 1}, 
        {0, 1, 7}, 
        {0, 3, 2}, 
        {3, 4, 7}, 
        {1, 3, 5}, 
        {1, 4, 1}, 
        {1, 2, 3}, 
    };

    vector<int> result = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << " to other vertices:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": " << result[i] << endl;
    }        
    return 0;
}