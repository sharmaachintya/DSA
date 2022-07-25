#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adj;

        void addEdge(int u, int v, int w)
        {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        void printAdjList()
        {
            for (auto i : adj)
            {
                cout<<i.first<<"->";
                for (auto j : i.second)
                {
                    cout<<j.first<<",";
                }
                cout<<endl;
            }
        }

        vector<pair<pair<int, int>, int>> primsMST(int vertex)
        {
            vector<int> key(vertex + 1, INT_MAX);
            vector<bool> mst(vertex + 1, false);
            vector<int> parent(vertex + 1, -1);

            key[0] = 0;
            parent[0] = -1;

            for (int i=0;i<vertex;i++)
            {
                int mini = INT_MAX;
                int u;

                // Finding minimum key value node
                for (int v=0;v<vertex;v++)
                {
                    if (mst[v] == false && key[v] < mini)
                    {
                        mini = key[v];           // Update mini
                        u = v;                   // Update node
                    }

                    mst[u] = true;              // Marking mst of that node as true

                    // Traverse for all it's neighbours
                    for (auto it: adj[u])
                    {
                        int v = it.first;
                        int w = it.second;

                        if (mst[v] == false && w < key[v])
                        {
                            parent[v] = u;       // Update parent
                            key[v] = w;          // Update key
                        }
                    }
                }
            }

            vector<pair<pair<int, int>, int>> res;
            for (int i=2;i<=vertex;i++)
            {
                res.push_back({{parent[i], i}, key[i]});
            }
            return res;
        }

};

int main()
{
    Graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 6);

    int vertex = 4;

    vector<pair<pair<int, int>, int>> res = g.primsMST(vertex);
    for (auto i: res)
    {
        cout<<i.first.first<<" "<< i.first.second<<" "<<i.second;
        cout<<endl;
    }

}