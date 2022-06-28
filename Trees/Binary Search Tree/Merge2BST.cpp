
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

//////////////////////////////////////////////////////////

void inorder(Node* root, vector<int> &head)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, head);
    head.push_back(root->data);
    inorder(root->right, head);
}

void mergeTwoSortedArrays(vector<int> head1, vector<int> head2, vector<int> &head)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < head1.size() && j < head2.size())
    {
        if (head1[i] < head2[j])
        {
            head[k] = head1[i];
            i++;
        }
        else
        {
            head[k++] = head2[j];
            j++;
        }
    }
    while (i < head1.size())
    {
        head[k++] = head1[i];
        i++;
    }
    while (j < head2.size())
    {
        head[k++] = head2[j];
        j++;
    }
}

Node* inorderToBST(int s, int e, vector<int> &head)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node* root = new Node(head[mid]);
    root->left = inorderToBST(s, mid - 1, head);
    root->right = inorderToBST(mid + 1, e, head);
    return root;
}

//////////////////////////////////////////////////////////

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root1 = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root1);

    Node* root2 = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root2);

    // Get inorder of both BST's
    vector<int> head1;
    inorder(root1, head1);
    vector<int> head2;
    inorder(root2, head2);


    // Merge 2 sorted arrays
    vector<int> head(head1.size() + head2.size());
    mergeTwoSortedArrays(head1, head2, head);

    Node* root = inorderToBST(0, head.size() - 1, head);
    levelOrderTrav(root);
    
}