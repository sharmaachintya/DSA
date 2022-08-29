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

Node* buildTree(Node* root)
{
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for left node of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right node of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void solve(Node* root, int k, vector<int> path, int &count)
{
    if (root == NULL)
        return;
    
    path.push_back(root->data);

    solve(root->left, k, path, count);
    solve(root->right, k, path, count);

    int n = path.size();
    int sum = 0;
    for (int i=n-1;i>=0;i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }
    }
}

int kPathSum(Node* root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    return count;
}

int main()
{
    
}