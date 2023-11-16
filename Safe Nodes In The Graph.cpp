#include <bits/stdc++.h> 

bool dfs(int node,vector<int> adj[],vector<int> &pathvis,vector<int>&vis,vector<int>&check){
    vis[node]=1;
    pathvis[node]=1;
    check[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            if(dfs(x,adj,pathvis,vis,check)==true){
                check[node]=0;
                return true;
            }
        }
        else if(pathvis[x]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathvis[node]=0;
    return false;
}

vector<int> safeNodes(vector<vector<int>> &edges, int v, int e) {
	vector<int> adj[v];
    for(int i=0;i<e;++i){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(v,0);
    vector<int> pathvis(v,0);
    vector<int> check(v,0);
    vector<int> ans;
    for(int i=0;i<v;++i){
        if(!vis[i]){
            dfs(i,adj,pathvis,vis,check);
        }
    }
    for(int i=0;i<v;++i){
        if(check[i]==1){
            ans.push_back(i);
        }
    }
    return ans;
}
