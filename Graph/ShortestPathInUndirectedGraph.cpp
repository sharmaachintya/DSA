#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t)
{
    // create Adj list
    unordered_map<int, list<int>> adj;
    for (int i=0;i<edges.size();i++)    
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do BFS and prepare parent DS
    queue<int> q;
    vector<int, int> parent;
    vector<int, bool> visited;

    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

    // traverse for all neighbours
        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // Find the shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);
    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{
        
}