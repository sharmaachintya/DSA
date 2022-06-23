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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> ans;
        
        if (root == NULL)
        {
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0,0)));
        
        while (!q.empty())
        {
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();
            TreeNode* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontnode->val);
            
            if (frontnode->left)
            {
                q.push(make_pair(frontnode->left, make_pair(hd-1, lvl+1)));
            }
            if (frontnode->right)
            {
                q.push(make_pair(frontnode->right, make_pair(hd+1, lvl+1)));
            }
        }
        vector<int> res;
        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    res.push_back(k);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};