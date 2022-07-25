#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
        bool cmp(vector<int> &a , vector<int> &b)
        {
            return a[2] < b[2];
        }

        void make_Set(vector<int> &parent, vector<int> &rank, int vertex)
        {
            for (int i=0;i<vertex;i++)
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
            return parent[node] = findParent(parent, parent[node]);  // Path compression
        }

        void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
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
                parent[v] = u;                       // Can also do parent[u] = v 
                rank[u]++;                           // and rank[v]++;
            }
        }

        int minSpanningTree(vector<vector<int>> &edges, int vertex)
        {
            sort(edges.begin(), edges.end(), cmp);

            vector<int> parent(vertex);
            vector<int> rank(vertex);
            int minW = INT_MAX;

            for (int i=0;i<edges.size();i++)
            {
                int u = findParent(parent, edges[i][0]);
                int v = findParent(parent, edges[i][1]);
                int w = findParent(parent, edges[i][2]);

                if (u != v)
                {
                    minW = minW + w;
                    unionSet(parent, rank, u, v);
                }
            }
            return minW;
        }
};

int main()
{
    Graph g;

    vector<vector<int>> edges = {{0, 1, 3},
                                 {0, 3, 5},
                                 {1, 2, 1},
                                 {2, 3, 8}};
    
    int vertex = 4;
    cout<<g.minSpanningTree(edges, vertex);
}