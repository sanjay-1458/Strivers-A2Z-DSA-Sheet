vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int> dr={0,-1,0,1};
    vector<int> dc={-1,0,1,0};
    int clr=image[x][y];
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    image[x][y]=p;
    while(!q.empty()){
        pair<int,int> node=q.front();
        q.pop();
        int row=node.first;
        int col=node.second;
        for(int i=0;i<4;++i){
            int newr=row+dr[i];
            int newc=col+dc[i];
            if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && image[newr][newc]==clr){
                vis[newr][newc]=1;
                q.push({newr,newc});
                image[newr][newc]=p;
            }
        }
    }
    return image;
}
