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

////////////////////////////////////////////////////////////////////////////


void leftTraversal(Node* root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    

    ans.push_back(root->data);
    if(root->left)
    {
        leftTraversal(root->left, ans);
    }
    else
    {
        leftTraversal(root->right, ans);
    }
}

void leafNodes(Node* root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
    
}

void rightTraversal(Node* root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        rightTraversal(root->right, ans);
    }
    else
    {
        rightTraversal(root->left, ans);
    }
    ans.push_back(root->data);
}


vector<int> boundaryTraversal(Node* root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);

    // left Traversal for left Subtree
    leftTraversal(root->left, ans);

    // leaf Nodes of left subtree
    leafNodes(root->left, ans);

    // leaf Nodes of right subtree
    leafNodes(root->right, ans);

    // right Traversal for right Subtree
    rightTraversal(root->right, ans);

    return ans;
}

///////////////////////////////////////////////////////////////////////////

int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);
 
    vector<int> ans = boundaryTraversal(root);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}