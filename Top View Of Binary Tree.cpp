
#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        TreeNode<int>* node=q.front().first;
        int x=q.front().second;
        q.pop();
        if(mp.find(x)==mp.end()){
            mp[x]=node->data;
        }
        if(node->left!=nullptr){
            q.push({node->left,x-1});
        }
        if(node->right!=nullptr){
            q.push({node->right,x+1});
        }
    }
    vector<int> ans;
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}
