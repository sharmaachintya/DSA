#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        vector<Node*> neighbors;
        Node() 
        {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) 
        {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) 
        {
            val = _val;
            neighbors = _neighbors;
        }
};

void dfs(Node* node, Node* copy, vector<Node*> &vis)
{
    vis[copy->val] = copy;
    
    // Traversing for all the neighbors
    for (auto x : node->neighbors)
    {
        if (vis[x->val] == NULL)
        {
            Node* newNode = new Node(x->val);
            (copy->neighbors).push_back(newNode);
            dfs(x, newNode, vis);
        }
        else
        {
            (copy->neighbors).push_back(vis[x->val]);
        }
    }
}

Node* cloneGraph(Node* node)
{
    if (node == NULL)
        return NULL;
    vector<Node*> visited(1000, NULL);
    Node* copy = new Node(node->val);   // Clone Graph
    dfs(node, copy, visited);
    return copy;
}
int main()
{
    Node* node = NULL;
}