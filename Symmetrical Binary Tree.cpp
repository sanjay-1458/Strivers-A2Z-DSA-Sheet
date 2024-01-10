

bool preorder(TreeNode<int> *n1,TreeNode<int> *n2){
    if(n1==nullptr || n2==nullptr){
        if(n1==nullptr && n2==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    if(n1->data!=n2->data) return false;
    bool a=preorder(n1->left, n2->right);
    bool b=preorder(n1->right, n2->left);
    return (a && b);
}

bool isSymmetric(TreeNode<int> *root)
{
    return preorder(root,root);
}
