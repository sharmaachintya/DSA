#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////
// Using DFS

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

/////////////////////////////////////////////////////////////////////////
// Using BFS

bool cycleDetection(int n, vector<pair<int, int>> edges)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(n);
    for (int i=1;i<=n;i++)
    {
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }
    }

    // push all nodes with 0 indegree in queue
    queue<int> q;
    for (int i=1;i<=n;i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do BFS
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        cnt++;

        // check for all neighbours
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if (cnt != n)
        return true;
    else
        return false;
}


////////////////////////////////////////////////////////////////////////

int main()
{

}