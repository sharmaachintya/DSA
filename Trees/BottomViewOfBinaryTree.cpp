class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        
        map<int,int> TopNode;
        queue<pair<Node*,int>> q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* Frontnode = temp.first;
            int hd = temp.second;
            
            TopNode[hd] = Frontnode->data;
            
            if (Frontnode->left)
            {
                q.push(make_pair(Frontnode->left, hd-1));
            }
            if (Frontnode->right)
            {
                q.push(make_pair(Frontnode->right, hd+1));
            }
        }
        for (auto i : TopNode)
        {
            ans.push_back(i.second);
        }
    }
};