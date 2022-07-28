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
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root)
{
    cout<<"Enter the data for root node: "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for left Node: "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right node: "<<endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void childrenSumProp(Node* root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
        child = child + root->left->data;
    if (root->right)
        child = child + root->right->data;
    
    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    childrenSumProp(root->left);
    childrenSumProp(root->right);

    int temp = 0;
    if (root->left)
        temp = temp + root->left->data;
    if (root->right)
        temp = temp + root->right->data;
    if (root->left || root->right)
        root->data = temp;
}

int main()
{
    Node* root = NULL;

    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    inorder(root);

    childrenSumProp(root);
    cout<<endl;

    inorder(root);

}