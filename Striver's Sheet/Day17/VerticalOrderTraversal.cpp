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

vector<int> verticalOrderTraversalOfBT(Node* root)
{
    vector<int> res;
    map<int, map<int, vector<int>>> nodes;   // first int = Horizontal distance second int = level and last vector is to store list of nodes
    queue<pair<Node*,pair<int,int>>> q;      // fisrt int = Horizontal distance and second int = level
    if (root == NULL)
    {
        return res;
    }

    q.push(make_pair(root,make_pair(0,0)));

    while (!q.empty())
    {
        pair<Node*,pair<int,int>> temp = q.front();
        q.pop();
        Node* FrontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(FrontNode->data);

        if (FrontNode->left)
        {
            q.push(make_pair(FrontNode->left, make_pair(hd-1, lvl+1)));
        }
        if (FrontNode->right)
        {
            q.push(make_pair(FrontNode->right, make_pair(hd+1, lvl+1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                res.push_back(k);
            }
        }
    }
    return res;
}

int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);

    vector<int> ans = verticalOrderTraversalOfBT(root);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}