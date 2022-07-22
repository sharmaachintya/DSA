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
                adj[v].push_back(u);
        }

        void printAdjList()
        {
            for (auto i : adj)
            {
                cout<<i.first<<"->";
                for (auto j : i.second)
                {
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }

        bool bfsBipartite(int node, vector<int> &color)
        {
            queue<int> q;
            q.push(node);
            color[node] = 0;

            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                // Traversing all the neighbours
                for (auto neighbours : adj[front])
                {
                    if (color[neighbours] == -1)
                    {
                        color[neighbours] = 1 - color[front];
                        q.push(neighbours);
                    }
                    else if (color[neighbours] == color[front])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        bool checkBipartite(int vertex)
        {
            vector<int> color(vertex+1, -1);
            
            // Traversing for all the components of graph
            for (int i=0;i<vertex;i++)
            {
                if (color[i] == -1)
                    if(!bfsBipartite(i, color))
                        return false;
            }
            return true;
        }
};

int main()
{
    Graph g;

    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(2, 8, 0);
    // g.addEdge(3, 4, 0);
    // g.addEdge(8, 5, 0);
    // g.addEdge(4, 5, 0);
    // g.addEdge(5, 6, 0);
    // g.addEdge(6, 7, 0);

    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 7, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(6, 5, 0);
    g.addEdge(5, 8, 0);

    int vertex = 8;

    g.printAdjList();
    if(g.checkBipartite(vertex))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}