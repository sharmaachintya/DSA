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

        void printAdj()
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

        vector<int> djikstraShortestPath(int vertex, int source)
        {
            vector<int> dist (vertex, INT_MAX);
            set<pair<int, int>> st;                 // First int denotes the distance of that node and Second int denotes the node

            dist[source]  = 0;
            st.insert(make_pair(0, source));

            while(!st.empty())
            {
                // fetch top record of Set
                auto top = *(st.begin());

                int nodeDist = top.first;
                int node = top.second;

                // remove the top record
                st.erase(st.begin());

                // Traversing for all the neighbours
                for (auto neighbours : adj[node])
                {
                    if (nodeDist + neighbours.second < dist[neighbours.first])
                    {
                        auto record = st.find(make_pair(dist[neighbours.first], neighbours.first));

                        // record found 
                        if (record != st.end())
                        {
                            st.erase(record);
                        }

                        // update distance array
                        dist[neighbours.first] = nodeDist + neighbours.second;

                        // push record in set
                        st.insert(make_pair(dist[neighbours.first], neighbours.first));
                    }
                }
            }
            return dist;
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

    g.printAdj();

    int vertex = 4;
    vector<int> ans = g.djikstraShortestPath(vertex, 0);
    for (auto i : ans)
    {
        cout<<i<<" ";
    }

}