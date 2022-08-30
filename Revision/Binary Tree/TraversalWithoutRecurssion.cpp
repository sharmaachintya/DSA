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
            left = right = NULL;
        }
};

void inorder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout<<curr->data<<" ";

        curr = curr->right;
    }
}

void preorder(Node* root)
{
    stack<Node*> s;
    s.push(root);

    while(!s.empty())
    {
        Node* curr = s.top();
        cout<<curr->data<<" ";
        s.pop();

        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}





int main()
{
    
}