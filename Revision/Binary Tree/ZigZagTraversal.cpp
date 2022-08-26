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


vector<vector<int>> zigZagTraversal(Node* root)
{
    vector<vector<int>> res;
    if (root== NULL)
        return res;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i=0;i<size;i++)
        {
            Node* temp = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                zigZagTraversal(root->left);
            }
            if (temp->right)
            {
                zigZagTraversal(root->right);
            }
        }
        leftToRight = !leftToRight;

        res.push_back(ans);
    }
    return res;
}

int main()
{
    
}