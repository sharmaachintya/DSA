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

void solve(Node* root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;
    if (ans.size() == lvl)
        ans.push_back(root->data);
    solve(root->right, ans, lvl + 1);
    solve(root->left, ans, lvl+1);
}

vector<int> rightView(Node* root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 8 -1 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<int> ans = rightView(root);
    for (auto it: ans)
        cout<<it<<" ";
}