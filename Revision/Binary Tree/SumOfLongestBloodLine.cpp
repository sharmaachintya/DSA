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


void solve(Node* root, int len, int maxLen, int &sum, int maxSum)
{
    if (root == NULL)
        return;

    if (len > maxLen)
    {
        len = maxLen;
        sum = maxSum;
    }

    if (len == maxLen)
    {
        maxSum = max(maxSum, sum);
    }

    sum = sum + root->data;

    solve(root->left, len + 1, maxLen, sum, maxSum);
    solve(root->right, len + 1, maxLen, sum, maxSum);
}

int sumOfLongestBloodLine(Node* root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root, len, maxLen, sum, maxSum);
    return 0;
}


int main()
{

}