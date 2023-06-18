#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
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

    cout<<"Enter the data of left node of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data of right node of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

bool isIdentical(Node* r1, Node* r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL && r2 != NULL)
        return false;
    if (r1 != NULL && r2 == NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool val = r1->data == r2->data;

    if (left && val && right)
        return true;
    
    return false;
}

int main()
{
    Node* root1 = NULL;
    root1 = buildTree(root1);
    Node* root2 = NULL;
    root2 = buildTree(root2);
    //1 3 7 8 -1 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<isIdentical(root1, root2);
}