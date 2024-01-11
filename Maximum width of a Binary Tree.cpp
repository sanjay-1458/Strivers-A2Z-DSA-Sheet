/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long s=q.size();
            long long left=0,right=0,mn=q.front().second;;
            bool flag=false;
            while(s--){
                TreeNode* node=q.front().first;
                long long data=q.front().second-mn;
                q.pop();
                if(!flag){
                    left=data;
                    flag=true;
                }
                right=data;
                if(node->left){
                    q.push({node->left,data*2});
                }
                if(node->right){
                    q.push({node->right,data*2+1});
                }
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
