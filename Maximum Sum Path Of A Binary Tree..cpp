int fun(BinaryTreeNode<int> *node,int &ans){
    if(node==nullptr) return 0;
    int left=max(0,fun(node->left,ans));
    int right=max(0,fun(node->right,ans));
    ans=max(left+right+node->data,ans);
    return max(left,right)+node->data;
}


int maxPathSum(BinaryTreeNode<int> *root)
{
    int ans=INT_MIN;
    fun(root,ans);
    return ans;
}
