int savingMoney(int n, int source, int destination, int k, vector<vector<int>> &trains)
{
    vector<pair<int,int>> adj[n];
    for(int i=0;i<trains.size();++i){
        int u=trains[i][0];
        int v=trains[i][1];
        int wt=trains[i][2];
        adj[u].push_back({v,wt});
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    vector<int> dist(n,1e9);
    dist[source]=0;
    q.push({0,{source,0}});
    while(!q.empty()){
        auto it=q.top();
        q.pop();
        int node=it.second.first;
        int steps=it.second.second;
        int wt=it.first;
        if(node==destination && steps<=k+1){
            return wt;
        }
        for(auto x:adj[node]){
            if(wt+x.second<dist[x.first]){
                dist[x.first]=wt+x.second;
                q.push({dist[x.first],{x.first,steps+1}});
            }
        }
    }
    return -1;
}
