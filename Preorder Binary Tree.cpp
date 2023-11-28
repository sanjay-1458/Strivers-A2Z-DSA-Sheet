
#include<bits/stdc++.h>
vector<int> preOrder(TreeNode<int> * root){
    stack<TreeNode<int>*> stk;
    stk.push(root);
    vector<int> ans;
    while(!stk.empty()){
        TreeNode<int> *node=stk.top();
        stk.pop();
        ans.push_back(node->data);
        if(node->right!=nullptr){
            stk.push(node->right);
        }
        if(node->left!=nullptr){
            stk.push(node->left);
        }
    }
    return ans;
}
