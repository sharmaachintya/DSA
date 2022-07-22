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

        vector<int> topoSortKahn(int vertex)
        {
            vector<int> indegree(vertex);
            queue<int> q;

            // Finding indegree of all nodes
            for (auto i : adj)
            {
                for (auto j : i.second)
                {
                    indegree[j]++;
                }
            }

            // Pushing all nodes with 0 indegree in queue
            for (int i=0;i<vertex;i++)
            {
                if (indegree[i] == 0)
                    q.push(i);
            }

            vector<int> ans;
            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                ans.push_back(front);

                // Traversing for all the neighbours
                for (auto neighbours : adj[front])
                {
                    indegree[neighbours]--;
                    if (indegree[neighbours] == 0)
                        q.push(neighbours);
                }
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
    vector<int> ans = g.topoSortKahn(vertex);

    for (auto i: ans)
    {
        cout<<i<<" ";
    }
}