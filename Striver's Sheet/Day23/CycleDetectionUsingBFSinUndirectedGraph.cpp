#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, int direction)
        {
            adj[u].push_back(v);

            if (direction == 0)                            // Undirected Graph
            {
                adj[v].push_back(u);
            }
        }

        void printAdj()
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

        bool isCyclePresent(int node, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, unordered_map<int, list<int>> &adj)
        {
            queue<int> q;
            q.push(node);
            visited[node] = 1;
            parent[node] = -1;             // We don't know the parent of source node

            while (!q.empty())
            {
                int frontNode = q.front();
                q.pop();

                // Traversing for all neighbours
                for (auto neighbours : adj[frontNode])
                {
                    if (visited[neighbours] == 1 && neighbours != parent[frontNode])
                    {
                        return true;
                    }
                    else if (!visited[neighbours])
                    {
                        q.push(neighbours);
                        visited[neighbours] = 1;
                        parent[neighbours] = frontNode;
                    }
                }
            }
            return false;
        }

        string bfsCycle(int vertex)
        {
            unordered_map<int, bool> visited;
            unordered_map<int, int> parent;
            for (int i=0;i<vertex;i++)
            {
                if (!visited[i])
                {
                    bool ans = isCyclePresent(i, visited, parent, adj);
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

    cout<<"Is cycle Present: "<<g.bfsCycle(vertex);
}