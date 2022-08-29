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

Node* lcaOfBT(Node* n1, Node* n2, Node* root)
{
    if (root == NULL)
        return NULL;
    
    if (root->data == n1->data || root->data == n2->data)
    {
        return root;
    }

    Node* leftAns = lcaOfBT(n1, n2, root->left);
    Node* rightAns = lcaOfBT(n1, n2, root->right);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    if (leftAns != NULL && rightAns == NULL)
        return rightAns;
    else
        return NULL;
}

int main()
{
    
}