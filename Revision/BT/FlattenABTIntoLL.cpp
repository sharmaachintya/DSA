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

void flattenBT(Node* root)
{
    Node* curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            Node* pred = curr->left;
            while (pred->right)
                pred = pred->right;
            
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    flattenBT(root);
}