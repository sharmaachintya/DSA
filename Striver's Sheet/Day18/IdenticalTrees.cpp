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

bool identicalTrees(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }

    bool leftAns = identicalTrees(root1->left, root2->left);
    bool rightAns = identicalTrees(root1->right, root2->right);

    bool val = (root1->data == root2->data);

    if (leftAns && rightAns && val)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root1 = NULL;
    Node* root2 = NULL;

    root1 = buildTree(root1);
    root2 = buildTree(root2);

    cout<<identicalTrees(root1, root2)<<endl;
}