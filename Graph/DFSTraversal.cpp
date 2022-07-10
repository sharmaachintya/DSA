#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &comp)
{
    comp.push_back(node);
    vis[node] = true;

    for (auto i:adj[node])
    {
        if (!vis[node])
        {
            dfs(i, vis, adj, comp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    // Prepare Adjecent List
    for (int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int> comp;
            dfs(i, visited, adj, comp);
            ans.push_back(comp);
        }
    }
    return ans;
}

int main()
{

}