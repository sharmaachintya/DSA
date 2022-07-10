#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, int direction)
        {
            // direction = 0 -> Undirected Graph
            // direction = 1 -> Directed Graph

            // create an edge from u to v
            adj[u].push_back(v);
            if (direction == 0)
            {
                adj[v].push_back(u);
            }
        }

        void printAdjList()
        {
            for (auto i:adj)
            {
                cout<<i.first<<" -> ";
                for (auto j:i.second)
                {
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};

int main()
{
    int n;
    cout<<"Enter the Number of Nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the Number of Nodes: ";
    cin>>m;

    Graph g;

    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        // Creating a undirected Graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();
}