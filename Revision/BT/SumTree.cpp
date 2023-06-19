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

pair<bool, int> solve(Node* root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    bool val = root->data == left.second + right.second;

    bool leftAns = left.first;
    bool rightAns = right.first;

    pair<bool, int> ans;

    if (leftAns && rightAns && val)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
        ans.second = 0;
    }
    return ans;
}

bool isSumTree(Node* root)
{
    return solve(root).first;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 8 -1 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1  

    cout<<isSumTree(root);
}