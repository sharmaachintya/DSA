#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ans = false;

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

bool match(Node* root, Node* subRoot)
{
    if (root != NULL && subRoot != NULL)
    {
        bool leftA = match(root->left, subRoot->left);
        bool rightA = match(root->right, subRoot->right);

        if ((root->data == subRoot->data) && leftA && rightA)
            return true;
        else 
            return false;
    }
    else if (root == NULL && subRoot == NULL)
        return true;
    else
        return false;
}

void inorder(Node* root, Node* subRoot)
{
    if (root != NULL)
    {
        inorder(root->left, subRoot);

        bool x = match(root, subRoot);
        if (x)
            ans = x;
        
        inorder(root->right, subRoot);
    }
}

bool isSubtree(Node* root, Node* subRoot)
{
    inorder(root, subRoot);
    return ans;
}

int main()
{

}