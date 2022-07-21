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
                adj[v].push_back(u); // Undirected Graph
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

        void depthFirstSearch(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &comp)
        {
            comp.push_back(node);
            visited[node] = 1;

            // Traversing all the neighbours
            for (auto i: adj[node])
            {
                if(!visited[i])
                {
                    depthFirstSearch(i, adj, visited, comp);
                }
            }
        }

        vector<vector<int>> dfs(int vertex)
        {
            unordered_map<int, bool> visited;
            vector<vector<int>> ans;

            for (int i=0;i<vertex;i++)
            {
                if (!visited[i])
                {
                    vector<int> comp;
                    depthFirstSearch(i, adj, visited, comp);
                    ans.push_back(comp);
                }
            }
            return ans;
        }
};


int main()
{
    Graph g;

    g.addEdge(0, 4, 0);
    g.addEdge(4, 2, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(1, 5, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(5, 3, 0);
    g.addEdge(2, 3, 0);
    
    

    int vertex = 5;

    //g.printAdj();

    vector<vector<int>> ans = g.dfs(vertex);

    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl; 
    }

}