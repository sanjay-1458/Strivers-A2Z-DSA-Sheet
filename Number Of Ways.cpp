int numberOfWays(int n, int m, vector<vector<int>> roads)
{
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;++i){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int mod=1e9+7;
    vector<int> dist(n,1e9);
    vector<int> ways(n,0);
    dist[0]=0;
    ways[0]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,0});
    while(!q.empty()){
        auto it=q.top();
        q.pop();
        int node=it.second;
        int wt=it.first;
        for(auto x:adj[node]){
            if(wt+x.second<dist[x.first]){
                dist[x.first]=wt+x.second;
                ways[x.first]=ways[node];
                q.push({dist[x.first],x.first});
            }
            else if(wt+x.second==dist[x.first]){
                ways[x.first]=(ways[x.first]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
     
}
