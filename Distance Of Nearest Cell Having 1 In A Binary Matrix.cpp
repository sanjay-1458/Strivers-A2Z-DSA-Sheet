vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mat[i][j]==1){
                q.push({i,j});
            }
        }
    }
    vector<int> dr={0,-1,0,1},dc={-1,0,1,0};
    int cnt=1;
    while(!q.empty()){
        int time=q.size();
        while(time--){
            pair<int,int> node=q.front();
            int row=node.first;
            int col=node.second;
            q.pop();
            for(int k=0;k<4;++k){
                int newr=row+dr[k];
                int newc=col+dc[k];
                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && !mat[newr][newc]){
                    ans[newr][newc]=cnt;
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
        cnt++;
    }
    
    
    
    
    
    return ans;
}
