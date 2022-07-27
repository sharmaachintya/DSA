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
    cout<<"Enter the data of root node: "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout<<"Enter the data for left node: "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right node: "<<endl;
    root->right = buildTree(root->right);
    return root;
}

bool isSymmetricHelp(Node* left, Node* right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    if (left->data != right->data)
    {
        return false;
    }

    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(Node* root)
{
    if (root == NULL)
    {
        return false;
    }

    return isSymmetricHelp(root->left, root->right);
}

int main()
{
    Node* root = NULL;

    // Creation of Binary tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    bool ans = isSymmetric(root);

    if (ans == 1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}