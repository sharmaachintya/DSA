/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void leftTraversal(Node* root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        
        ans.push_back(root->data);
        if (root->left)
        {
            leftTraversal(root->left, ans);
        }
        else
        {
            leftTraversal(root->right, ans);
        }
    }
    
    void leafTraversal(Node* root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
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


    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        
        // Printing left part
        leftTraversal(root->left, ans);
        
        
        // Printing leaf nodes of left subtree
        leafTraversal(root->left, ans);
        
        //Printing leaf nodes of right subtree
        leafTraversal(root->right, ans);
        
        //Printing right part
        rightTraversal(root->right, ans);
        
        return ans;
    }
};