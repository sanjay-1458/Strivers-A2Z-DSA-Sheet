int fun(int ind,int W,vector<int>&profit){

	if(W==0){
		return 0;
	}
	if(ind==0){
		return W*profit[0];
	}
	int exclude=fun(ind-1,W,profit),include=0;
	if(W-(ind+1)>=0){
		include=profit[ind]+fun(ind,W-(ind+1),profit);
	}
	return max(include,exclude);
}


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int i=0;i<n;++i){
		dp[i][0]=0;
	}
	for(int j=0;j<=n;++j){
		dp[0][j]=j*price[0];
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=n;++j){
			int exclude=dp[i-1][j],include=0;
			if(j-(i+1)>=0){
				include=price[i]+dp[i][j-(i+1)];
			}
			dp[i][j]=max(include,exclude);
		}
	}
	return dp[n-1][n];
}
