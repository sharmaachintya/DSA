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

void inorder(Node* root, vector<int> &in)
{
    if (root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool BTisBST(Node* root)
{
    vector<int> in;
    inorder(root, in);
    for (int i=0;i<=in.size()-1;i++)
    {
        if (in[i+1] < in [i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // 50 20 70 10 30 110 -1               // BST
    Node* root = NULL;

    // Creation of Binary tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1   // BT
    cout<<BTisBST(root);

}