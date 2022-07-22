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
                for (auto j: i.second)
                {
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }

        bool isCyclePresent(int node, unordered_map<int, list<int>> &adj, int n)
        {
            // prepare indegree for all node
            vector<int> indegree(n);
            for (int k=0;k<n;k++)
            {
                for (auto i : adj)
                {
                    for (auto j: i.second)
                    {
                        indegree[j]++;
                    }
                }
            }

            queue<int> q;

            // Pushing all the nodes with 0 indegree in the queue
            for (int i=0;i<n;i++)
            {
                if (indegree[i] == 0)
                    q.push(i);
            }

            int cnt = 0;
            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                cnt++;

                // Checking for all the neighbours 
                for (auto neighbours : adj[front])
                {
                    indegree[neighbours]--;
                    if (indegree[neighbours] == 0)
                        q.push(neighbours);
                }
            }
            if (cnt != n)
                return true;
            else
                return false;

        }

        string cycleBFS(int vertex)                                 // Using Kahn's Algorithm
        {
            unordered_map<int, bool> visited;
            for (int i=0;i<vertex;i++)
            {
                if (!visited[i])
                {
                    bool ans = isCyclePresent(i, adj, vertex);
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
    cout<<"Is Cycle Present: "<<g.cycleBFS(vertex);    
}