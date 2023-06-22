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

Node* solve(vector<int> in, vector<int> post, int inS, int inE, int &index, int n)
{
    if (index >= n || inS > inE)
        return NULL;
    
    int element = post[index--];
    Node* root = new Node(element);

    int pos = findPos(in, element, n);
    
    root->left = solve(in, post, inS, pos-1, index, n);
    root->right = solve(in, post, pos+1, inE, index, n);

    return root;
}

Node* buildTree(vector<int> in, vector<int> post, int n)
{
    int inE = 0;
    int inS = n-1;
    int index = 0;
    Node* ans = solve(in, post, inS, inE, index, n);
    return ans;
}

int main()
{
    vector<int> in = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> post = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = in.size();
    Node* root = buildTree(in, post, n);
}