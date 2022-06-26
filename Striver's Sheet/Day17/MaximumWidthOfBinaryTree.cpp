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

int maxWidth(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        int size = q.size();
        int mmin = q.front().second;
        int first, last;
        for (int i=0;i<size;i++)
        {
            long long curr_Ind = q.front().second - mmin;
            Node* frontNode = q.front().first;
            q.pop();

            if(i == 0)
            {
                first = curr_Ind;
            }
            if (i == size - 1)
            {
                last = curr_Ind;
            }

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, 2*curr_Ind + 1));
            }
            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, 2*curr_Ind + 2));
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);

    int ans = maxWidth(root);
    cout<<ans;

}