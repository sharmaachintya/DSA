/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int findPos(vector<int> inorder, int element, int n)
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
    
    
    
    TreeNode* solve(vector<int> inorder, vector<int> postorder, int inorderS, int inorderE, int &index, int n)
    {
        // base case
        if (index < 0 || inorderS > inorderE)
        {
            return NULL;
        }
        
        // creating root node
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        
        // Finding position of root node in INORDER vector
        int position = findPos(inorder, element, n);
        
        // Recurssive Calls
        root->right = solve(inorder, postorder, position + 1, inorderE, index, n);
        root->left = solve(inorder, postorder, inorderS, position - 1, index, n);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderS = 0;
        int inorderE = inorder.size()-1;
        int n = inorder.size();
        int index = n - 1;
        TreeNode* ans = solve(inorder, postorder, inorderS, inorderE, index, n);
        return ans;
    }
};