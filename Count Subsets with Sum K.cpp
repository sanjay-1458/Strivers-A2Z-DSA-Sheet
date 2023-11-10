int fun(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
	if(sum==0){
		return 1;
	}
	if(ind==0){
		if(arr[0]==sum){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[ind][sum]!=-1) return dp[ind][sum];
	int take=0,nottake=0;
	nottake=fun(ind-1,sum,arr,dp);
	if(arr[ind]<=sum){
		take=fun(ind-1,sum-arr[ind],arr,dp);
	}
	return dp[ind][sum]=take+nottake;
}



int findWays(vector<int>& arr, int k)
{	vector<vector<int>> dp(arr.size()+1,vector<int>(k+1,0));
	for(int i=0;i<arr.size();++i){
		dp[i][0]=1;
	}
	int mod=1e9+7;
	if(arr[0]<=k)
		dp[0][arr[0]]=1;
	for(int i=1;i<arr.size();++i){
		for(int j=1;j<=k;++j){
			int take=0,nottake=0;
			nottake=dp[i-1][j];
			if(arr[i]<=j){
				take=dp[i-1][j-arr[i]];
			}
			dp[i][j]=(take%mod+nottake%mod)%mod;
		}
	}
	return dp[arr.size()-1][k];
}
