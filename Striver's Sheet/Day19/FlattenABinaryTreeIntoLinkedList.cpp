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
            this->left = left;
            this->right = right;
        }
};

Node* buildTree(Node* root)
{
    cout<<"Enter the data for root Node: "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for left node: "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right node: "<<endl;
    root->right = buildTree(root->right);
    return root;
}

void flatten(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    Node* curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            Node* prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
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

    flatten(root);

    while (root != NULL)
    {
        cout<<root->data<<" ";
        root = root->right;
    }
}