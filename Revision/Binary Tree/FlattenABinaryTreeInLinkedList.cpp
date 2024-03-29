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

void flattenBT(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    Node* curr = root;
    while(curr != NULL)
    {
        if (curr->left)
        {
            Node* prev = prev->right;
            while (prev->right)
                prev = prev->right;
            
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
}

int main()
{
    
}