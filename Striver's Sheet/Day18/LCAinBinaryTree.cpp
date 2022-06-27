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

Node* lcaInBT(Node* root, Node* p, Node* q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p->data || root->data == q->data)
    {
        return root;
    }
    Node* leftAns = lcaInBT(root->left, p, q);
    Node* rightAns = lcaInBT(root->right, p,q);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    return NULL;
}


int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);
    Node* p = root->left->right;
    Node* q = root->right->left;
    Node* ans = lcaInBT(root, p, q);
    cout<<"Lowest Common Ancesstor: "<<ans->data<<endl;
    
}