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

int findPos(vector<int> in, int k, int n)
{
    for (int i=0;i<n;i++)
    {
        if (in[i] == k)
            return i;
    }
    return -1;
}

Node* solve(vector<int> in, vector<int> pre, int inS, int inE, int &index, int n)
{
    if (index >= n || inS > inE)
        return NULL;
    
    int element = pre[index++];
    Node* root = new Node(element);

    int pos = findPos(in, element, n);
    
    root->left = solve(in, pre, inS, pos-1, index, n);
    root->right = solve(in, pre, pos+1, inE, index, n);

    return root;
}

Node* buildTree(vector<int> in, vector<int> pre, int n)
{
    int inE = 0;
    int inS = n-1;
    int index = 0;
    Node* ans = solve(in, pre, inS, inE, index, n);
    return ans;
}

int main()
{
    vector<int> in = {3, 1, 4, 0, 5, 2};
    vector<int> pre = {0, 1, 3, 4, 2 ,5};
    int n = in.size();
    Node* root = buildTree(in, pre, n);
}