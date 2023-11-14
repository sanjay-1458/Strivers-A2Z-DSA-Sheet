#include<bits/stdc++.h>

int getTotalIslands(int** arr, int n, int m)
{
   int cnt=0;
   vector<vector<int>> vis(n,vector<int>(m,0));
   for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
         if(!vis[i][j] && arr[i][j]){
            cnt++;
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j]=1;
            while(!q.empty()){
               pair<int,int> node=q.front();
               q.pop();
               int xi=node.first;
               int yj=node.second;
               for(int k=-1;k<=1;++k){
                  for(int l=-1;l<=1;++l){
                     int newi=xi+k;
                     int newj=yj+l;
                     if((newi>=0 && newi<n) && (newj>=0 && newj<=m) && !vis[newi][newj] && arr[newi][newj]){
                        vis[newi][newj]=1;
                        q.push({newi,newj});
                     }
                  }
               }
            }
         }
      }
   }
   return cnt;
}
