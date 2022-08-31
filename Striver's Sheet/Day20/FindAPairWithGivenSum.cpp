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

void inroder(Node* root, vector<int> &in)
{
    if (root == NULL)
        return;
    
    inroder(root->left, in);
    in.push_back(root->data);
    inroder(root->right, in);
}

bool pairSum(Node* root, int targetSum)
{
    vector<int>in;
    inroder(root, in);

    int s = 0;
    int e = in.size() - 1;

    while (s < e) 
    {
        int sum = in[s] + in[e];
        if (sum == targetSum)
        {
            return true;
        }
        if (sum < targetSum)
        {
            s++;
        }
        if (sum > targetSum)
        {
            e--;
        }
    }
    return false;
}


int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    int sum = 90;
    cout<<pairSum(root, sum);
}