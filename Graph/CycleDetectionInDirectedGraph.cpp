#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDeteced = detectCycle(neighbour, visited, dfsVisited, adj);
            if (cycleDeteced)
                return true;
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool cycleDetection(int n, vector<pair<int, int>> edges)
{
    // Create adj list
    unordered_map<int, list<int>> adj;
    for (int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
    }

    // check for all components of the graph
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            bool checkCycle = detectCycle(i, visited, dfsVisited, adj);
            if (checkCycle)
                return true;
        }
    }
    return false;
}

int main()
{

}