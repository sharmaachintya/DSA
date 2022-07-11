#include<iostream>
#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////
// CYCLE DETECTION IN UNDIRECTED GRAPH


// USING BFS

bool cyclicBFS(int src, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;
    queue<int> q;

    parent[src] = -1;
    visited[src] = 1;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbours: adj[front])
        {
            if (visited[neighbours] == 1 && neighbours != parent[front])
            {
                return true;
            }
            else if (!visited[neighbours])
            {
                q.push(neighbours);
                visited[neighbours] = 1;
                parent[neighbours] = front;
            }
        }
    }
    return false;
}

string detectCycle(vector<vector<int>> edges, int n, int m)
{
    // Prepare adjacenecy list
    unordered_map<int, list<int>> adj;
    for (int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    unordered_map<int, bool> visited;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            bool ans = cyclicBFS(i, adj, visited);
            if (ans == 1)
                return "YES";
        }
    }
    return "NO";
}

///////////////////////////////////////////////////////

// USING DFS

bool isCyclicDFS(int node,int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool ans = isCyclicDFS(neighbour, node, visited, adj);
            if (ans)
                return true;
            else if(neighbour != parent)
            {
                return true;
            }
        }
    }
    return false;
}


string cyclicDFS(vector<vector<int>> edges, int n, int m)
{
    // prepare adjacency list

    unordered_map<int, list<int>> adj;
    for (int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if (ans == 1)
                return "YES";
        }
    }
    return "NO";
}











//////////////////////////////////////////////////////



int main()
{
    
}