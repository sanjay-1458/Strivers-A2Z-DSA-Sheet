class Graph {
    bool bfs(int src,vector<int>&vis,vector<int> adj[]){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int src,int parent,vector<int>&vis,vector<int> adj[]){
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it]){
                if(dfs(it,src,vis,adj)==true){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
public:
    bool detectCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;++i){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
