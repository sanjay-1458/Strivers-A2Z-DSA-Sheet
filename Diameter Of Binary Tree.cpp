/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int funh(TreeNode<int>* node,int& maxi){
    if(node==nullptr){
        return 0;
    }
    int lh=funh(node->left,maxi);
    int rh=funh(node->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root){
    int val=0;
	funh(root,val);
    return val;
}
