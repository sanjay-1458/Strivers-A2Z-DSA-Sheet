void bfs(int i,int j,vector<vector<int>>&vis,int &cnt){
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;
    cnt--;
    int dr[]={0,-1,0,1};
    int dc[]={-1,0,1,0};
    while(!q.empty()){
        pair<int,int> node=q.front();
        q.pop();
        int r=node.first;
        int c=node.second;
        for(int k=0;k<4;++k){
            int newr=r+dr[k],newc=c+dc[k];
            if(newr>=0 && newr<vis.size() && newc>=0 && newc<vis[0].size() &&!vis[newr][newc]){
                vis[newr][newc]=1;
                cnt--;
                q.push({newr,newc});
            }
        }
    }
}


int matrixTraps(int n,int m,vector<vector<int>> &mat)
{
    int cnt=n*m;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> arr;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(mat[i][j]==0){
                    arr.push_back({i,j});
                }
            }
            if(mat[i][j]==1){
                vis[i][j]=1;
                cnt--;
            }
        }
    }
    for(int i=0;i<arr.size();++i){
        int r=arr[i][0],c=arr[i][1];
        if(!vis[r][c]){
            bfs(r,c,vis,cnt);
        }
    }
    return cnt;
}
