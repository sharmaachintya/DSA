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

vector<int> bottomViewofBT(Node* root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    
    map<int, int> TopNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> Front = q.front();
        q.pop();
        Node* temp = Front.first;
        int hd = Front.second;

        TopNode[hd] = temp->data;

        if (temp->left)
            q.push(make_pair(temp->left, hd-1));
        if (temp->right)
            q.push(make_pair(temp->right, hd+1));
    }
    for(auto i : TopNode)
    {
        ans.push_back(i.second);
    }
}

int main()
{
    
}