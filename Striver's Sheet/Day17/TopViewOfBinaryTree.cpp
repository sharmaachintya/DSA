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

vector<int> TopViewOfBT(Node* root)
{
    vector<int> ans;
    // Base case
    if (root == NULL)
    {
        return ans;
    }
    map<int,int> TopNode;
    queue<pair<Node*,int>> q; 

    q.push(make_pair(root, 0));
    
    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* FrontNode = temp.first;
        int hd = temp.second;
        
        if (TopNode.find(hd) == TopNode.end())
        {
            TopNode[hd] = FrontNode->data;
        }

        if (FrontNode->left)
        {
            q.push(make_pair(FrontNode->left, hd-1));
        }

        if (FrontNode->right)
        {
            q.push(make_pair(FrontNode->right, hd+1));
        }
    }
    for (auto i : TopNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);

    vector<int> ans = TopViewOfBT(root);

    cout<<"TOP VIEW OF BINARY TREE: "<<endl;
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}