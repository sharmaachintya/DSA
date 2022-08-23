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

pair<bool, int> sumTreeFast(Node* root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    
    pair<bool, int> leftAns = sumTreeFast(root->left);
    pair<bool, int> rightAns = sumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool cond = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;
    if (left && right && cond)
    {
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
    }
    else
    {
        ans.first = false;
        ans.second = 0;
    }

    return ans;
}

bool sumTree(Node* root)
{
    return sumTreeFast(root).first;
}



int main()
{
    
}