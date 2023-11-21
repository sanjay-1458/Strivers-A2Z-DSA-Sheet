#include <bits/stdc++.h> 
int numberOfIslands(vector<vector<int>> &grid, int n, int m)
{
	int cnt=0;
	vector<vector<int>> vis(n,vector<int>(m,0));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(grid[i][j]==1 && vis[i][j]==0){
				cnt++;
				queue<pair<int,int>> q;
				q.push({i,j});
				vis[i][j]=1;
				while(!q.empty()){
					int row=q.front().first;
					int col=q.front().second;
					q.pop();
					for(int j=-1;j<=1;++j){
						for(int k=-1;k<=1;++k){
							int newr=row+j;
							int newc=col+k;
							if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] &&!vis[newr][newc]){
								vis[newr][newc]=1;
								q.push({newr,newc});
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}
