#include <bits/stdc++.h> 


int fun(int i,int j,int n,vector<vector<int>>&arr,vector<vector<int>>&dp){
	if(i==n-1){
		return arr[i][j];
	}
	if(dp[i][j]!=-1) return dp[i][j];
	int p1=arr[i][j]+fun(i+1,j,n,arr,dp);
	int p2=arr[i][j]+fun(i+1,j+1,n,arr,dp);
	return dp[i][j]=min(p1,p2);
}

int minimumPathSum(vector<vector<int>>& arr, int n){
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i=0;i<n;++i){
		dp[n-1][i]=arr[n-1][i];
	}
	for(int i=n-2;i>=0;--i){
		for(int j=i;j>=0;--j){
			int p1=dp[i+1][j];
			int p2=dp[i+1][j+1];
			dp[i][j]=min(p1,p2)+arr[i][j];
		}
	}
	return dp[0][0];
}
