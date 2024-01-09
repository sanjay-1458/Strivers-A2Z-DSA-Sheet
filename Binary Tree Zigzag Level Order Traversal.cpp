class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int cnt=0;
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                temp.push_back(node->val);
            }
            cnt++;
            if(cnt%2==0){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
