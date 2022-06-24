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
    
    int findPosition(vector<int> in, int element, int n)
    {
        for (int i=0;i<n;i++)
        {
            if (in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    
    
    TreeNode*  solve(vector<int> pre, vector<int> in, int inorderStart, int inorderEnd, int &index, int size)
    {
        // Base case
        if (index >= size || inorderStart > inorderEnd)
        {
            return NULL;
        }
        
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(in, element, size);
        
        // Recursive Calls
        
        root->left = solve(pre, in, inorderStart, pos - 1, index, size);
        root->right = solve(pre, in, pos + 1, inorderEnd, index, size);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        int n = inorder.size();
        int index = 0;
        TreeNode* ans = solve(preorder, inorder, inorderStart, inorderEnd, index ,n);
        return ans;
    }
};