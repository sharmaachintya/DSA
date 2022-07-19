#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i=0;i<n;i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);          // Path compression
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;        // can also do parent[u] = v and rank[v]++
        rank[u]++;
    }
}


int minSpanningTree(vector<vector<int>> edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);

    vector<int> rank(n);
    vector<int> parent(n);
    makeSet(parent, rank, n);
    int minW = INT_MAX;

    for (int i=0;i<edges.size();i++)
    {
        int u = findParent(parent, edges[i][0]); 
        int v = findParent(parent, edges[i][1]);
        int w = findParent(parent, edges[i][2]);

        if (u != v)
        {
            minW = minW + w;
            unionSet(u, v, parent, rank);
        }
    }
    return minW;
}



int main()
{
    
}