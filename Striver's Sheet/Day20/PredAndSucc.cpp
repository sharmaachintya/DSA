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

pair<int, int> predAndSuc(Node* root, int k)
{
    Node* temp = root;
    int pred = -1;
    int suc = -1;

    while (temp->data != k)
    {
        if (temp->data > k)
        {
            pred = temp->data;
            temp = temp->left;
        }
        if (temp->data < k)
        {
            suc = temp->data;
            temp = temp->right;
        }
    }

    // Finding pred and succ
    Node* leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    Node* rightTree = temp->right;
    while (rightTree != NULL)
    {
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred, suc);
    return ans;
}

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    int k = 20;
    pair<int, int> ans = predAndSuc(root, k);
    cout<<"Pred: "<<ans.first<<endl;
    cout<<"Succ: "<<ans.second;
}