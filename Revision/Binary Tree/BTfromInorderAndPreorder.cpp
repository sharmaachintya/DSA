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

int findPos(vector<int> in, int element, int n)
{
    for (int i=0;i<n;i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node* solve(vector<int> pre, vector<int> in, int inorderS, int inorderE, int index, int n)
{
    if (index >= n || inorderS > inorderE)
    {
        return NULL;
    }

    int element = pre[index++];
    Node* root = new Node(element);

    int pos = findPos(in, element, n);

    root->left  = solve(pre, in, inorderS, pos - 1, index, n);
    root->right = solve(pre, in, pos + 1, inorderE, index, n);

    return root;
}

Node* buildTree(vector<int> &pre, vector<int> &in)
{
    int n = in.size();
    int inorderS = 0;
    int inorderE = n - 1;
    int index = 0;
    Node* ans = solve(pre, in, inorderS, inorderE, index, n);
    return ans;
}

int main()
{

}