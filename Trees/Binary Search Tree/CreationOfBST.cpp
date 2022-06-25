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

pair<int, int> minMax(Node* root)
{
    pair<int, int> ans;
    Node* mini = root;
    Node* maxi = root;
    while (mini->left != NULL)
    {
        mini = mini->left;
    }
    int temp = mini->data;
    ans.first = temp;
    while (maxi->right != NULL)
    {
        maxi = maxi->right;
    }
    temp = maxi->data;
    ans.second = temp;
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

    pair<int, int> ans = minMax(root);

    cout<<"MAX ELEMENT IN BST: "<<ans.first<<endl;
    cout<<"MIN ELEMENT IN BST: "<<ans.second<<endl;
}