vector<int> findSchedule(int n, vector<pair<int, int>> &arr)
{
    vector<int> adj[n+1];
    vector<int> ans;
    vector<int> indeg(n+1,0);
    for(int i=0;i<arr.size();++i){
        adj[arr[i].second].push_back(arr[i].first);
        indeg[arr[i].first]++;
    }
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto x:adj[node]){
            if(indeg[x]==1){
                q.push(x);
            }
            indeg[x]--;
        }
    }
    if(ans.size()==n){
        return ans;
    }
    else{
        return {};
    }
}
