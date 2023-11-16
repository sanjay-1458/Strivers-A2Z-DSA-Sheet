void dfs(int node,vector<int>&vis,stack<int>&stk,vector<pair<int,int>> adj[]){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x.first]){
            dfs(x.first,vis,stk,adj);
            stk.push(x.first);
        }
    }
    stk.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;++i){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    vector<int> vis(n,0);
    stack<int> stk;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            dfs(i,vis,stk,adj);
        }
    }
    vector<int> distarr(n,1e5+4);
    distarr[0]=0;
    while(!stk.empty()){
        int node=stk.top();
        stk.pop();
        int dist=distarr[node];
        for(auto x:adj[node]){
            int newn=x.first;
            int newd=x.second+dist;
            if(distarr[newn]>newd){
                distarr[newn]=newd;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<n;++i){
        if(distarr[i]<=1e5){
            ans.push_back(distarr[i]);
        }
        else{
            ans.push_back(-1);
        }
    }
    return ans;
}
