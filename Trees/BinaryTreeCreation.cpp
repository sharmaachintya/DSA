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
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void preOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    Node* root = NULL;

    // Creation of Binary tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level Order Traversal
    cout<<"Printing level order Traversal: "<<endl;
    levelOrderTraversal(root);


    cout<<"INORDER TRAVERSAL: "<<endl;
    inOrder(root);

    cout<<endl;

    cout<<"PREORDER TRAVERSAL: "<<endl;
    preOrder(root);

    cout<<endl;

    cout<<"POSTORDER TRAVERSAL: "<<endl;
    postOrder(root);

    cout<<endl;
}