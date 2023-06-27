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

Node* lcaInBST(Node* root, Node* p, Node* q)
{
    if (root == NULL)
        return NULL;
    
    while (root != NULL)
    {
        if (root->data < p->data && root->data < q->data)
            root = lcaInBST(root->left, p, q);
        if (root->data > p->data && root->data > q->data)
            root = lcaInBST(root->right, p, q);
        else
            return root;
    }
    return NULL;
}

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    cout<<endl;
}