#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root)
{
    cout<<"Enter the Data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout<<"Enter the data for left Node of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right Node of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void solve(Node* root, int k, int &count, vector<int> paths)
{
    if (root == NULL)
        return;
    
    paths.push_back(root->data);

    solve(root->left, k, count, paths);
    solve(root->right, k, count, paths);

    int n = paths.size();
    int sum = 0;
    for (int i=n-1;i>=0;i--)
    {
        sum += paths[i];
        if (sum == k)
            count++;
    }
    paths.pop_back();
}

int kPath(Node* root, int k)
{
    vector<int> paths;
    int count = 0;
    solve(root, k, count, paths);
    return count;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<kPath(root, 10);
}