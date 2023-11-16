vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    vector<int> adj[n];
    for(int i=0;i<edges.size();++i){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<pair<int,int>> q;
    vector<int> dist(n,1e9);
    dist[src]=0;
    q.push({src,0});
    while(!q.empty()){
        int node=q.front().first;
        int wt=q.front().second;
        q.pop();
        for(auto x:adj[node]){
            if(wt+1<dist[x]){
                dist[x]=wt+1;
                q.push({x,wt+1});
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<n;++i){
        if(dist[i]==1e9){
            ans.push_back(-1);
        }
        else{
            ans.push_back(dist[i]);
        }
    }
    return ans;
}
