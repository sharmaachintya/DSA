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

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<front->data<<" ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

void InorderTraversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

void PreorderTraversal(Node* root)
{
    if (root == NULL)
        return;
    
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void PostOrder(Node* root)
{
    if (root == NULL)
        return;
    
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    cout<<root->data<<" ";
}



int main()
{
    
}