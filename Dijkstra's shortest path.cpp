vector<int> dijkstra(vector<vector<int>> &edge, int n, int e, int src)
{
    vector<pair<int,int>> adj[n];
    for(int i=0;i<e;++i){
        int u=edge[i][0];
        int v=edge[i][1];
        int wt=edge[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    set<pair<int,int>> st;
    vector<int> dist(n,1e6);
    dist[src]=0;
    st.push({0,src});
    while(!st.empty()){
        int node=st.top().second;
        int wt=st.top().first;
        st.pop();
        for(auto x:adj[node]){
            if(dist[node]+x.second<dist[x.first]){
                if(dist[x.first]!=1e6){
                    st.erase({dist[x.first].})
                }
                dist[x.first]=dist[node]+x.second;
                st.push({dist[x.first],x.first});
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<n;++i){
        ans.push_back(dist[i]);
    }
    return ans;
}
