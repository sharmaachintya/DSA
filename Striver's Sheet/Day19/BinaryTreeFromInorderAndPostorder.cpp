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

int findPos(vector<int> &inorder, int element, int n)
{
    for (int i=0;i<n;i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node* solve(vector<int> &inorder, vector<int> &postorder, int inorderS, int inorderE, int index, int size)
{
    if (index < 0 || inorderS > inorderE)
    {
        return NULL;
    }


    int element = postorder[index--];
    Node* root = new Node(element);

    // Finding postion of root node in inorder
    int pos = findPos(inorder, element, size);

    // Recursive Calls
    root->right = solve(inorder, postorder, pos + 1, inorderE, index, size);
    root->left = solve(inorder, postorder, inorderS, pos - 1, index, size);

    return root;
}

Node* buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int inorderS = 0;
    int n = inorder.size(); 
    int inorderE = n - 1;
    int index = n-1;
    Node* ans = solve(inorder, postorder, inorderS, inorderE, index, n);
    return ans;
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

int main()
{
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Node* ans = buildTree(inorder, postorder);

    //inOrder(ans);                                 // To verify the answer

}