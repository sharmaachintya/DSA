#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
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

Node* buildTree(Node* root)
{
    cout<<"Enter the Data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout<<"Enter the data for left Node of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right Node of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

vector<int> zigZagTrav(Node* root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    
    bool leftToRight = true;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);

        for (int i=0;i<size;i++)
        {
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            temp[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
        leftToRight = !leftToRight;

        for (auto it : temp)
            ans.push_back(it);
    }
    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 8 -1 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 -1 6 7 -1 -1 8 -1 -1

    vector<int> ans = zigZagTrav(root);
    for (auto it: ans)
        cout<<it<<" ";
}