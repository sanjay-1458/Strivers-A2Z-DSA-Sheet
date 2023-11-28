
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        while(!q.empty()){
            int time=q.size();
            vector<int> v;
            while(time--){
                TreeNode *node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};



vector<int> levelOrder(TreeNode<int> * root){
    vector<int> ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        vector<TreeNode<int>*> temp;
        while(!q.empty()){
            temp.push_back(q.front());
            ans.push_back(q.front()->data);
            q.pop();
        }
        for(int i=0;i<temp.size();++i){
            if(temp[i]->left!=nullptr){
                q.push(temp[i]->left);
            }
            if(temp[i]->right!=nullptr){
                q.push(temp[i]->right);
            }
        }
    }
    return ans;
}
