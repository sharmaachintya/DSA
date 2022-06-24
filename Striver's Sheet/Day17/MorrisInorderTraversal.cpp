#include<iostream>
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

void morrisTraversal(Node* root)
{
    Node* curr = root;
    if (root == NULL)
    {
        return;
    }
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            Node* prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}


int main()
{

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;

    root = buildTree(root);

    cout<<"MORRIS INORDER TRAVERSAL: "<<endl;
    morrisTraversal(root);

}