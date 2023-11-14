void dfs(int node,vector<int>&vis,vector<int> adj[]){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,vis,adj);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    int cnt=0;
    vector<int> adj[n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j && roads[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(n,0);
    for(int i=0;i<n;++i){
        if(!vis[i]){
            cnt++;
            dfs(i,vis,adj);
        }
    }
    return cnt;
}
