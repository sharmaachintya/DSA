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

pair<int,int> fastDia(Node* root)
{
    if (root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = fastDia(root->left);
    pair<int, int> right = fastDia(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, left.second) + 1;

    return ans;
}


int diameterOfBT(Node* root)
{
    return fastDia(root).first;
}

int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);
    int ans = diameterOfBT(root);
    cout<<"Diameter of Binary Tree: "<<ans;
}