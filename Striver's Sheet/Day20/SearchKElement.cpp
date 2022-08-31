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

void inorder(Node* root, vector<int> &in)
{
    if (root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool searchKElement(Node* root, int k)
{
    vector<int> in;
    inorder(root, in);
    for (int i=0;i<in.size();i++)
    {
        if (in[i] == k)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    int k = 11;
    cout<<searchKElement(root, k);
}