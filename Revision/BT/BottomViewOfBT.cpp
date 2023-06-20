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

vector<int> bottomView(Node* root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> bottNodes;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        bottNodes[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }
    for (auto it : bottNodes)
        ans.push_back(it.second);
    
    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 8 -1 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<int> ans = bottomView(root);

    for (auto it : ans)
        cout<<it<<" ";
}