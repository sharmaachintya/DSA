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

void zigZagTraversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    bool leftToRight = true;
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> ans(n);
        for (int i=0;i<n;i++)
        {
            Node* temp = q.front();
            q.pop();
            int index;
            if (leftToRight)
            {
                index = i;
            }
            else
            {
                index = n - i - 1;
            }

            ans[index] = temp->data;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        leftToRight = !leftToRight;
        for (auto i : ans)
        {
            cout<<i<<" ";
        }
    }
}

int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);
 
    zigZagTraversal(root);
}