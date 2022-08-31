#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d)
        {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* &root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while (data != -1)
    {
        insertIntoBST(root,data);
        cin>>data;
    }
}

Node* solve(vector<int> &pre, int min, int max, int &i)
{
    if (i >= pre.size())
        return NULL;
    
    if (pre[i] < min || pre[i] > max)
        return NULL;

    Node* root = new Node(pre[i++]);
    root->left = solve(pre, min, root->data, i);
    root->right = solve(pre, root->data, max, i);
    return root;
}


Node* buildTree(vector<int> pre)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(pre, min, max, i);
}

int main()
{
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    Node* root = buildTree(pre);
}