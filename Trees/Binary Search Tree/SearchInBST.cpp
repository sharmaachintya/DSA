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

bool searchNode(Node* root, int val)
{
    Node* temp = root;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        val > temp->data ? temp = temp->right : temp = temp->left;
    }
    return false;
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    cout<<"Printintg BST: "<<endl;
    levelOrderTrav(root);

    int val = 5;
    if(searchNode(root, val))
    {
        cout<<val<<" Node is present"<<endl;
    }
    else
    {
        cout<<val<<" Node is not present"<<endl;
    }
}