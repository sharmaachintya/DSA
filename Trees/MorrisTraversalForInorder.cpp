void MorrisTraversal(Node* root)
{
    Node* curr , prec;

    if (root == NULL)
    {
        return;
    }

    curr = root;
    while(curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout<<curr->data;
            curr = curr->right;
        }
        else
        {
            prec = curr->left;
            while(prec->right != NULL && prec->right != curr)
            {
                prec = prec->right;
            }
            if (prec->right == NULL)
            {
                prec->right = curr;
                curr = curr->left;
            }
            else
            {
                prec->right = NULL;
                cout<<curr->data;
                curr = curr->right;
            }
        }
    }
}