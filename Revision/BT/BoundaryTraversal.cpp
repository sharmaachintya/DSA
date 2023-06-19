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

void leftNodes(Node* root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    
    ans.push_back(root->data);
    if (root->left)
        leftNodes(root->left, ans);
    else
        leftNodes(root->right, ans);
}

void leafNodes(Node* root, vector<int> &ans)
{
    if (root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL)
        ans.push_back(root->data);
    
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

void rightNodes(Node* root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    
    if (root->right)
        leftNodes(root->right, ans);
    else
        leftNodes(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundaryTrav(Node* root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    
    // Adding left Subtree Nodes in answer
    leftNodes(root->left, ans);

    // Adding leaf Nodes in answer of left subtree
    leafNodes(root->left, ans);

    // Adding leaf Nodes in answer of right subtree
    leafNodes(root->right, ans);

    // Adding left Subtree Nodes in answer
    rightNodes(root->right, ans);

    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<int> ans = boundaryTrav(root);

    for(auto it: ans)
        cout<<it<<" ";
}