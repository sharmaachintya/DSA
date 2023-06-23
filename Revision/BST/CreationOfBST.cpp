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

void createBST(Node* &root)
{
    int data;
    cin>>data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin>>data;
    }
}

void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    createBST(root);

    inorder(root);
}