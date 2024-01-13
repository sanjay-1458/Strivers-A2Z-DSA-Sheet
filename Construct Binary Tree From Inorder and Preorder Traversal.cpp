
TreeNode<int>* build(int &p,int l,int h,vector<int> &inorder, vector<int> &preorder){
    if(l<=h){
        int ind=-1;
        for(int i=l;i<=h;++i){
            if(preorder[p]==inorder[i]){
                ind=i;
                break;
            }
        }
        if(ind==-1) return nullptr;
        TreeNode<int> * node=new TreeNode(inorder[ind]);
        p++;
        node->left=build(p,l,ind-1,inorder,preorder);
        node->right=build(p,ind+1,h,inorder,preorder);
        return node;
    }
    else{
        return nullptr;
    }
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n=inorder.size();
    int p=0;
	return build(p,0,n-1,inorder,preorder);
}
