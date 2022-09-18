bool isSymmetricFast(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if (root1 == NULL && root2 == NULL)
        return root1 == root2;
    bool ans = root1->data == root2->data;
    bool leftAns = isSymmetricFast(root1->left, root2->right);
    bool rightAns = isSymmetricFast(root1->right, root2->left);
    if (ans && leftAns && rightAns)
        return true;
    return false;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
   BinaryTreeNode<int>* root1 = root;
   BinaryTreeNode<int>* root2 = root;
   if (!root)
       return true;
   return isSymmetricFast(root1->left, root2->right);
}