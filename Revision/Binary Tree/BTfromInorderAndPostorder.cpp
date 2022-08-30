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

Node* solve(vector<int> post, vector<int> in, int inorderS, int inorderE, int index , int n)
{
    if (index >= n || inorderS > inorderE)
    {
        return NULL;
    }

    int element = post[index--];
    Node* root = new Node(element);

    int pos = findPos(in, element, n);

    root->left = solve(post, in, inorderS, pos - 1, index, n);
    root->right = solve(post, in, pos + 1, inorderE, index, n);

    return root;
}

Node* buildTree(vector<int> post, vector<int> in)
{
    int inorderS = 0;
    int n = in.size();
    int inorderE = n - 1;
    int index = n - 1;
    Node* ans = solve(post, in, inorderS, inorderE, index, n);
    return ans;
}

int main()
{
    
}