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


        bool isCyclePresent(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
        {
            visited[node] = 1;
            dfsVisited[node] = 1;

            // Check for all the neighbours
            for (auto neighbours : adj[node])
            {
                if (!visited[node])
                {
                    bool ans = isCyclePresent(neighbours, adj, visited, dfsVisited);
                    if (ans)
                        return true;
                }
                else if (dfsVisited[neighbours])
                {
                    return true;
                }
            }
            return false;
        }

        string cycleDFS(int vertex)
        {
            unordered_map<int, bool> visited;
            unordered_map<int, bool> dfsVisited;

            for (int i=0;i<vertex;i++)
            {
                if (!visited[i])
                {
                    bool ans = isCyclePresent(i, adj, visited, dfsVisited);
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

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(2, 4);

    int vertex = 4;

    g.printAdjList();
    cout<<"Is Cycle Present: "<<g.cycleDFS(vertex);
}