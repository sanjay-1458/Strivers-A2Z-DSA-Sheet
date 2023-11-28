
int heightOfBinaryTree(TreeNode<int> *root)
{
	int cnt=0;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        cnt++;
        while(size--){
            TreeNode<int>* node=q.front();
            q.pop();
            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
        }
    }
    return cnt;
}
