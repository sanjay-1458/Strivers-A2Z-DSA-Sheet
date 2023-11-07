#include <bits/stdc++.h> 

int fun(int i,int j,vector<vector<int>> &dp){
	if(i==0 && j==0){
		return 1;
	}
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int up=fun(i-1,j,dp);
	int left=fun(i,j-1,dp);
	return dp[i][j]=up+left;

}
int uniquePaths(int n, int m) {
	vector<vector<int>> dp(n,vector<int>(m,-1));
	return fun(n-1,m-1,dp);
}


int uniquePaths(int n, int m) {
	vector<vector<int>> dp(n,vector<int>(m,0));
	dp[0][0]=1;
	for(int i=1;i<m;++i){
		dp[0][i]=1;
	}
	for(int j=1;j<n;++j){
		dp[j][0]=1;
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			int up=dp[i-1][j];
			int left=dp[i][j-1];
			dp[i][j]=up+left;
		
		}
	}
	return dp[n-1][m-1];
}
