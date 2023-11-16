#include<bits/stdc++.h>
vector<int> topologicalSort1(vector<vector<int>> &graph, int e, int n) {
    vector<int> ans;
    vector<int> adj[n];
    vector<int> indeg(n,0);
    for(int i=0;i<e;++i){
        adj[graph[i][0]].push_back(graph[i][1]);
        indeg[graph[i][1]]++;
    }
    vector<int> vis(n,0);
    while(ans.size()<n){
        for(int i=0;i<n;++i){
            if(indeg[i]==0 && !vis[i]){
                vis[i]=1;
                ans.push_back(i);
                for(auto x:adj[i]){
                    indeg[x]--;
                }
            }
        }
    }
    return ans;
}
void dfs(int node,stack<int>&stk,vector<int> adj[],vector<int>&vis){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,stk,adj,vis);
            stk.push(x);
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int e, int n) {
    vector<int> ans;
    vector<int> adj[n];
    for(int i=0;i<e;++i){
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    stack<int> stk;
    vector<int> vis(n,0);
    for(int i=0;i<n;++i){
        if(!vis[i]){
            dfs(i,stk,adj,vis);
        }
    }
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}
