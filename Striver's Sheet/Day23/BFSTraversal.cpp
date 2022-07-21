#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
        unordered_map<int, list<int>> adj;      // adjacency list

        void addEdge(int u,int v, int direction)
        {
            adj[u].push_back(v);
            if (direction == 0)                // Undirected Graph
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

        void bfs(unordered_map<int, list<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node)
        {
            queue<int> q;
            q.push(node);
            visited[node] = 1;

            while (!q.empty())
            {
                int frontNode = q.front();
                q.pop();

                ans.push_back(frontNode);
                // Check for neighbours
                for (auto neighbours: adj[frontNode])
                {
                    if(!visited[neighbours])
                    {
                        q.push(neighbours);
                        visited[neighbours] = 1;
                    }
                }
            }
        }

        vector<int> BFS(int vertex)
        {
            unordered_map<int, bool> visited;
            vector<int> ans;

            for (int i=0;i<vertex;i++)
            {
                if(!visited[i])
                {
                    bfs(adj, ans, visited, i);
                }
            }
            return ans;
        }

};


int main()
{
    Graph g;

    // Edges vector which will be given in Q
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    

    g.printAdjList();

    int vertex = 4;

    vector<int> ans = g.BFS(vertex);
    for (auto i: ans)
    {
        cout<<i<<" ";
    }

}