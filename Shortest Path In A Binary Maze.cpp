#include<bits/stdc++.h>

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    int n=matrix.size(),m=matrix[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e5));
    int dc[]={0,1,0,-1};
    int dr[]={-1,0,1,0};
    if(matrix[src.first][src.second]==0){
            return -1;
    }
    if(src.first==dest.first && src.second==dest.second){
        if(matrix[src.first][src.second]==0){
            return -1;
        }
        else{
            return 0;
        }
    }
    queue<pair<int,pair<int,int>>> q;
    dist[src.first][src.second]=0;
    q.push({0,{src.first,src.second}});
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        int wt=q.front().first;
        q.pop();
        for(int k=0;k<4;++k){
            int newx=x+dr[k];
            int newy=y+dc[k];
            if(newx>=0 && newx<n && newy>=0 && newy<m && matrix[newx][newy] && wt+1<dist[newx][newy]){
                if(newx==dest.first && newy==dest.second){
                    return wt+1;
                }
                dist[newx][newy]=wt+1;
                q.push({1+wt,{newx,newy}});
                
            }
        }
    }
    return -1;
}
