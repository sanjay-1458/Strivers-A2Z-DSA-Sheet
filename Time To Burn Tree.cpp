#include<bits/stdc++.h>
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> parent;
    map<BinaryTreeNode<int>*,bool> vis;
    BinaryTreeNode<int>* st;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    if(root->data==start) st=root;
    while(!q.empty()){
        BinaryTreeNode<int>* node=q.front();
        q.pop();
        if(node->left){
            q.push(node->left);
            parent[node->left]=node;
        }
        if(node->right){
            q.push(node->right);
            parent[node->right]=node;
        }
        vis[node]=false;
        if(node->data==start) st=node;
    }
    int val=0;
    queue<pair<BinaryTreeNode<int>*,int>> qp;
    qp.push({st,0});
    vis[st]=true;
    while(!qp.empty()){
        BinaryTreeNode<int>* node=qp.front().first;
        int t=qp.front().second;
        val=max(val,t);
        qp.pop();
        if(node->left && !vis[node->left]){
            qp.push({node->left,t+1});
            vis[node->left]=true;
        }
        if(node->right && !vis[node->right]){
            qp.push({node->right,t+1});
            vis[node->right]=true;
        }
        if(parent[node] && !vis[parent[node]]){
            qp.push({parent[node],t+1});
            vis[parent[node]]=true;
        }
    }
    return val;
}
