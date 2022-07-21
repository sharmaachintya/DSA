#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, int direction)
        {
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
                cout<<i.first<<"->";
                for (auto j:i.second)
                {
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }

        bool isCyclePresent(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
        {
            visited[node] = 1;

            // Traversing for all the neighbours
            for (auto neighbours: adj[node])
            {
                if (!visited[neighbours])
                {
                    bool ans = isCyclePresent(neighbours, node, adj, visited);
                    if (ans)
                        return true;
                    else if (neighbours != parent)
                        return true;
                }
            }
            return false;
        }

        string dfsCycle(int vertex)
        {
            unordered_map<int, bool> visited;
            for (int i=0;i<vertex;i++)
            {
                if (!visited[i])
                {
                    bool ans = isCyclePresent(i, -1, adj, visited);
                    if (ans)
                        return "YES";
                }
            }
            return "NO";
        }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);

    int vertex = 3;

    cout<<"Is cycle present: "<<g.dfsCycle(vertex);

}