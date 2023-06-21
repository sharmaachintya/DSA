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

void solve(Node* root, int len, int &maxLen, int sum, int &maxSum)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        if (len == maxLen)
            maxSum = max(maxSum, sum);
        return;
    }
    sum = sum + root->data;

    solve(root->left, len+1, maxLen, sum, maxSum);
    solve(root->right, len+1, maxLen, sum, maxSum);
}

int sumLongest(Node* root)
{
    int sum, len, maxLen = 0;
    int maxSum = 1e-9;
    solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<sumLongest(root);
}