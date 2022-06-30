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

////////////////////////////////////////////////////////////////

int nodeCount(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1 + nodeCount(root->left) + nodeCount(root->right);
    return ans;
}

bool isCBT(Node* root, int index, int nodeCnt)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= nodeCnt)
    {
        return false;
    }
    bool left = isCBT(root->left, 2*index + 1, nodeCnt);
    bool right = isCBT(root->right, 2*index + 2, nodeCnt);

    return (left &&  right);
}

bool isMaxOrder(Node* root)
{
    // left node
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    // Only left child exists
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

bool isHeap(Node* root)
{
    int index = 0;
    int nodeCnt = nodeCount(root);
    if (isCBT(root, index, nodeCnt) && isMaxOrder(root))
    {
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////

int main()
{
    Node* root = NULL;

    // Creation of Binary tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<isHeap(root);
}