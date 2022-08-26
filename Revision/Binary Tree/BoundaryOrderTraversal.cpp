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

void leftSubTree(Node* root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
        leftSubTree(root->left, ans);
    else
        leftSubTree(root->right, ans);
}

void leafNodes(Node* root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

void rightSubTree(Node* root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
        rightSubTree(root->right, ans);
    else
        rightSubTree(root->left, ans);
    
    ans.push_back(root->data);
}

vector<int> boundary(Node* root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);
    // Printing left subtree except leaf nodes
    leftSubTree(root->left, ans);

    // Printing leaf nodes of left subtree
    leafNodes(root->left, ans);

    // Printing leaf nodes of right subtree
    leafNodes(root->right, ans);

    // Printing right subtree but in reverse order
    rightSubTree(root->right, ans);

    return ans;
}

int main()
{
    
}