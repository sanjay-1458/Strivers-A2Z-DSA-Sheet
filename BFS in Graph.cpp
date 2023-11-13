vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    vector<int> vis(n,0);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<adj[node].size();++i){
            if(!vis[adj[node][i]]){
                q.push(adj[node][i]);
                vis[adj[node][i]]=1;
            }
        }
    }
    return ans;
}
