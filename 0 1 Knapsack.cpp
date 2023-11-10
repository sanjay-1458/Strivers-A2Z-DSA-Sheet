#include <bits/stdc++.h> 

int fun(int ind,int W,vector<int>&wt,vector<int>&value,vector<vector<int>>&dp){
	if(W==0){
		return 0;
	}
	if(ind==0){
		if(wt[0]<=W){
			return value[0];
		}else{
			return 0;
		}
	}
	if(dp[ind][W]!=-1) return dp[ind][W];
	int exclude=fun(ind-1,W,wt,value,dp);
	int include=0;
	if(W-wt[ind]>=0){
		include=value[ind]+fun(ind-1,W-wt[ind],wt,value,dp);
	}
	return dp[ind][W]=max(exclude,include);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,0));

	for(int i=0;i<=maxWeight;++i){
		if(weight[0]<=i){
			dp[0][i]=value[0];
		}
	}

	for(int i=0;i<n;++i){
		dp[i][0]=0;
	}
	if(weight[0]<=maxWeight)
	dp[0][weight[0]]=value[0];
	for(int i=1;i<n;++i){
		for(int j=0;j<=maxWeight;++j){
			int exclude=dp[i-1][j];
			int include=0;
			if(j-weight[i]>=0){
				include=value[i]+dp[i-1][j-weight[i]];
			}
			dp[i][j]=max(include,exclude);
		}
	}
	return dp[n-1][maxWeight];
}
