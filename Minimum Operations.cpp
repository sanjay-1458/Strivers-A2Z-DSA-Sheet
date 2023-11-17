int minimumOperations(int n, int start, int end, vector<int> &a)
{
    int mod=1e3;
    vector<int> dist(1000,1e9);
    queue<pair<int,int>> q;
    if(start==end){
        return 0;
    }
    q.push({0,start});
    dist[start]=0;
    while(!q.empty()){
        int steps=q.front().first;
        int node=q.front().second;
        q.pop();
        for(int i=0;i<n;++i){
            int prod=((node%mod)*(a[i]%mod))%mod;
            if(steps+1<dist[prod]){
                dist[prod]=steps+1;
                q.push({steps+1,prod});
                if(prod==end){
                    return steps+1;
                }
            }
        }
    }
    return -1;
}
