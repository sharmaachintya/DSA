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

void levelOrder(Node* root)                          // LEVEL ORDER TRAVERSAL
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inOrder(Node* root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root)
{
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node* root = NULL;

    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"LEVEL ORDER TRAVERSAL"<<endl;
    levelOrder(root);
    cout<<"IN ORDER TRAVERSAL"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"PRE ORDER TRAVERSAL"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"POST ORDER TRAVERSAL"<<endl;
    postOrder(root);
}