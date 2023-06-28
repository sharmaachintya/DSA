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

void inorder(Node* root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root, ans);
    ans.push_back(root->data);
    inorder(root, ans);
}

bool twoSum(Node* root, int target)
{
    vector<int> ans;
    inorder(root, ans);
    int i = 0;
    int j = ans.size() - 1;
    while (i < j)
    {
        int sum = ans[i] + ans[j];
        if (sum == target)
            return true;
        if (sum > target)
            j--;
        else if (sum < target)
            i++;
    }
    return false;
}

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    cout<<endl;

    int target = 80;
    cout<<twoSum(root, target);
}