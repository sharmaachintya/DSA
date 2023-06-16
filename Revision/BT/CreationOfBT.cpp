#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data; 
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data = data;
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

    cout<<"Enter the data of left node of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data of right node of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    Node* root = NULL;

    // Creation of Binary Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}