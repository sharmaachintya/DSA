#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
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

        void doTopoSort(int node, unordered_map<int, list<int>> &adj, stack<int> &s, unordered_map<int, bool> &visited)
        {
            visited[node] = true;

            // Check for all neighbours
            for (auto neighbours : adj[node])
            {
                if (!visited[neighbours])
                {
                    doTopoSort(neighbours, adj, s, visited);
                }
            }
            s.push(node);
        }

        vector<int> topoSort(int vertex)
        {
            unordered_map<int, bool> visited;
            stack<int> s;

            for (int i=0;i<vertex;i++)
            {
                if (!visited[i])
                {
                    doTopoSort(i, adj, s, visited);
                }
            }

            vector<int> ans;
            while (!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
            return ans;
        }
};

int main()
{
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 2);

    int vertex = 4;
    vector<int> ans = g.topoSort(vertex);

    g.printAdjList();

    for (auto i:ans)
    {
        cout<<i<<" ";
    }
}