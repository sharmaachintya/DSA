#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }  
};

int findPos(vector<int> &in, int element, int n)
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

Node* solve(vector<int> &in, vector<int> &pre, int inorderS, int inorderE, int index, int n)
{
    if (index >= n || inorderS > inorderE)
    {
        return NULL;
    }

    int element = pre[index++];
    Node* root = new Node(element);

    // Find position of index element in inorder array
    int pos = findPos(in, element, n);

    // Recursive Calls 
    root->left = solve(in, pre, inorderS, pos - 1, index, n);
    root->right = solve(in, pre, pos + 1, inorderE, index, n);

    return root;
}

Node* constructTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();
    int inorderStart = 0;
    int inorderEnd = n - 1;
    int index = 0;
    Node* ans = solve(inorder, preorder, inorderStart, inorderEnd, index, n);
    return ans;
}

void inOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    vector<int> inorder = {40, 20, 50, 10, 60, 30};

    Node* ans = constructTree(inorder, preorder);

    //inOrder(ans);                                   // To verify answer
}