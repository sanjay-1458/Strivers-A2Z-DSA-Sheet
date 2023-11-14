void dfs(int node,vector<int>&res,vector<int> adj[],vector<int>&vis){
    vis[node]=1;
    res.push_back(node);
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,res,adj,vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(int i=0;i<E;++i){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(V,0);
    vector<vector<int>> ans;
    for(int i=0;i<V;++i){
        if(!vis[i]){
            vector<int> res;
            dfs(i,res,adj,vis);
            ans.push_back(res);
        }
    }
    return ans;
}
