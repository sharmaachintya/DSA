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

Node* insertIntoBST(Node* &root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while (data != -1)
    {
        insertIntoBST(root,data);
        cin>>data;
    }
}

Node* findMin(Node* root)
{
    Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node* deletionBST(Node* root, int ele)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == ele)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if (root->left != NULL && root->right == NULL)    // Left child only
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)   // Right child only
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = findMin(root->right)->data;
            root->data = mini;
            root->right = deletionBST(root->right, mini);
            return root;
        }
    }
    else if (ele > root->data)
    {
        root->right = deletionBST(root->right, ele);
        return root;
    }
    else
    {
        root->left = deletionBST(root->left, ele);
        return root;
    }
}

void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);
    inorder(root);
    cout<<endl;
    deletionBST(root, 70);
    inorder(root);
}