#include<iostream>
#include<vector>
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

void solve(Node* root, vector<int> &ans, int lvl)
{
    if (root == NULL)
    {
        return;
    }

    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, lvl+1);
    solve(root->right, ans, lvl+1);
}

vector<int> leftViewOfBT(Node* root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);

    vector<int> ans = leftViewOfBT(root);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}