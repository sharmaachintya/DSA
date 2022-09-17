class Solution {
public:
    int maxPath(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int left = max(0, maxPath(root->left, maxi));
        int right = max(0, maxPath(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return max(left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};