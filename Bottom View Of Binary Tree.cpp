#include <bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root){
    map<int,int> mp;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        TreeNode<int>* node=q.front().first;
        int x=q.front().second;
        mp[x]=node->data;
        q.pop();
        if(node->left){
            q.push({node->left,x-1});
        }
        if(node->right){
            q.push({node->right,x+1});
        }
    }
    vector<int> ans;
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}
