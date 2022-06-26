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

pair<int,int> predAndSucc(Node* root, int key)
{
    // Find the key
    Node* temp = root;
    int pred = -1;
    int suc = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            pred = temp->data;
            temp = temp->left;
        }
        if (temp->data < key)
        {
            suc = temp->data;
            temp = temp->right;
        }
    }

    // Find the Predecessor and Successor

    Node* leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    Node* rightTree = temp->right;
    while (rightTree != NULL)
    {
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred,suc);
    return ans;
}

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    cout<<"Printintg BST: "<<endl;
    levelOrderTrav(root);

    cout<<endl;

    int key = 20;
    pair<int,int> ans = predAndSucc(root, key);
    cout<<"Predecessor: "<<ans.first<<endl;
    cout<<"Successor: "<<ans.second<<endl;
}