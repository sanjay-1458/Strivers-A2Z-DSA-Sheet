#include <bits/stdc++.h> 

bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int> pathvis){
    vis[node]=1;
    pathvis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            if(dfs(x,adj,vis,pathvis)==true){
                return true;
            }
        }
        else if(pathvis[x]){
            return true;
        }
    }
    return false;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<int> adj[n];
    for(int i=0;i<e;++i){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> ans;
    for(int i=0;i<n;++i){
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        if(dfs(i,adj,vis,pathvis)==true){
            continue;
        }
        else{
            ans.push_back(i);
        }
    }
    return ans;
}
