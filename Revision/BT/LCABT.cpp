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

Node* lca(Node* root, int p, int q)
{
    if (root == NULL)
        return NULL;
    if (root->data == p || root->data == q)
        return root;
    
    Node* leftA = lca(root->left, p, q);
    Node* rightA = lca(root->right, p, q);

    if (leftA != NULL && rightA != NULL)
        return root;
    else if (leftA == NULL && rightA != NULL)
        return rightA;
    else if (leftA != NULL && rightA == NULL)
        return leftA;
    else
        return NULL;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Node* ans = lca(root, 7, 11);
    cout<<ans->data;
}