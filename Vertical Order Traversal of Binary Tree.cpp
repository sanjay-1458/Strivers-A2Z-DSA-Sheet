#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
	map<pair<int,int>,vector<int>> mp;
    queue<pair<TreeNode<int>*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        TreeNode<int>* node=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        q.pop();
        mp[{x,y}].push_back(node->data);
        if(node->left!=nullptr){
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right!=nullptr){
            q.push({node->right,{x+1,y+1}});
        }
    }
    vector<int> ans;
    for(auto &t:mp){
        vector<int> x=t.second;
        sort(x.begin(),x.end());
        ans.insert(ans.end(),x.begin(),x.end());
    }
    return ans;
}
