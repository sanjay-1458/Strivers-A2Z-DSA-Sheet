
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode*> stk1;
    stk1.push(root);
    while(!stk1.empty()){
        TreeNode *node=stk1.top();
        stk1.pop();
        ans.push_back(node->data);
        if(node->left!=nullptr){
            stk1.push(node->left);
        }
        if(node->right!=nullptr){
            stk1.push(node->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
