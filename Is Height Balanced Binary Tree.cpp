int fun(TreeNode<int>* node){
    if(node==nullptr) return 0;
    int left=fun(node->left);
    if(left==-1) return -1;
    int right=fun(node->right);
    if(right==-1) return -1;
    if(abs(left-right)>1){
        return -1;
    }
    return 1+max(left,right);
}

bool isBalancedBT(TreeNode<int>* root){
    if(fun(root)==-1) return false;
    return true;
}
