
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



/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class info

{

   public:

   int maxi;

   int mini;

   bool isBST;

   int size;

};

 

info solve(Node *root, int &ans)

{

   if(root == NULL)

       return {INT_MIN, INT_MAX, true, 0};

   info left = solve(root->left, ans);

   info right = solve(root->right, ans);

   info currNode;

   currNode.size = left.size + right.size + 1;

   currNode.maxi = max(root->data, right.maxi);

   currNode.mini = min(root->data, left.mini);

   

   if(left.isBST && right.isBST && (root->data> left.maxi && root->data < right.mini))

       currNode.isBST = true;

   else

       currNode.isBST = false;

   

   if(currNode.isBST)

       ans = max(ans, currNode.size);

   

   return currNode;

}

 

int largestBST(Node* root)  

{

   int maxSize = 0;

   info temp = solve(root, maxSize);

   return maxSize;

}

//////////////////////////////////////////////////////////

int main()
{
    // 50 20 70 10 30 110 -1
    Node* root = NULL;
    cout<<"Enter data to create BST" <<endl;
    takeInput(root);

    int ans = largestBST(root);
    cout<<ans<<endl;

    
}