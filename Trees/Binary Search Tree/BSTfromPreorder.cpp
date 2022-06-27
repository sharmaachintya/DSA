#include<iostream>
#include<queue>
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

void levelOrderTrav(Node* root)
{
    queue<Node*> q;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* &root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while (data != -1)
    {
        insertIntoBST(root,data);
        cin>>data;
    }
}

void preorderTrav(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorderTrav(root->left);
    preorderTrav(root->right);
}

//////////////////////////////////////////////////////////

Node* solve(vector<int> &pre, int min, int max, int &i)
{
    if (i >= pre.size())
    {
        return NULL;
    }

    if (pre[i] > max || pre[i] < min)
    {
        return NULL;
    }

    Node* root = new Node(pre[i++]);
    root->left = solve(pre, min, root->data, i);
    root->right = solve(pre, root->data, max, i);
    return root;
}


Node* bstFromPreorder(vector<int> &pre)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(pre, min, max, i);
}


//////////////////////////////////////////////////////////

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    //cout<<"Enter data to create BST" <<endl;
    //takeInput(root);

    // 50 20 10 30 70 110 -1 Preorder Traversal
    vector<int> pre = {50, 20, 70, 10, 30, 110};
    root = bstFromPreorder(pre);
    levelOrderTrav(root);

   
}