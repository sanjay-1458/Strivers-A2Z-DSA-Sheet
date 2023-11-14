#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    vector<vector<int>> vis(n,vector<int>(m,0));
    int one=0;
    int cnt=0;
    queue<pair<int,int>> q;
    vector<int> dr={0,-1,0,1};
    vector<int> dc={-1,0,1,0};
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1){
                one++;
            }
            else{
                continue;
            }
        }
    }
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
                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]==1){
                    one--;
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                    grid[newr][newc]=2;
                }
            }
        }
        cnt++;
    }
    if(one!=0){
        return -1;
    }
    return cnt==0?0:cnt-1;
}
