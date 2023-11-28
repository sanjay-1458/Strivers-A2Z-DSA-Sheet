 
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode *node=root;
    while(true){
        if(node!=nullptr){
            stk.push(node);
            node=node->left;
        }
        else{
            if(stk.empty()) break;
            node=stk.top();
            stk.pop();
            ans.push_back(node->data);
            node=node->right;
        }
    }
    return ans;
}
