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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        int ans = 0;
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second;    // To make the indexing start from zero
            int first,last;
            for (int i=0;i<size;i++)
            {
                long long curInd = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0)
                {
                    first = curInd;
                }
                if (i == size - 1)
                {
                    last = curInd;
                }
                if (node->left)
                {
                    q.push(make_pair(node->left, curInd*2 + 1));
                }
                if (node->right)
                {
                    q.push(make_pair(node->right, curInd*2 + 2));
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};