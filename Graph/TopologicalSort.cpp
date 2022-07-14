#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Using DFS
void topoSort(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topoSort(neighbour, visited, adj, s);
        }
    }
    s.push(node);
}


vector<int> topologicalSort(vector<pair<int,int>> edges, int n, int m)
{
    // Create adj list
    unordered_map<int, list<int>> adj;
    for (int i=0;i<m;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // check for all components
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, adj, s);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

/////////////////////////////////////////////////////////////////////////

int main()
{
    
}