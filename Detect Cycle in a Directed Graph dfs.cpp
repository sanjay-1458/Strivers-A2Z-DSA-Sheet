bool dfs(int node,vector<int> adj[],vector<int> pathvis,vector<int>&vis){
    vis[node]=1;
    pathvis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            if(dfs(x,adj,pathvis,vis)==true){
                return true;
            }
        }
        else if(pathvis[x]){
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adj[v];
    for(int i=0;i<e;++i){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(v,0);
    vector<int> pathvis(v,0);
    for(int i=0;i<v;++i){
        if(!vis[i]){
            if(dfs(i,adj,pathvis,vis)==true){
                return true;
            }
        }
    }
    return false;
}
