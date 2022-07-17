#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i=0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);
    for (int i=0;i<vertices;i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0,source));

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        // remove top record
        st.erase(st.begin());

        // traverse on neighbours
        for (auto neighbour : adj[topNode]) 
        {
            if (nodeDist + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // record found
                if (record != st.end())
                {
                    st.erase(record);
                }

                // update distance

                dist[neighbour.first] = nodeDist + neighbour.second;

                // record push in st
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main()
{
    
}