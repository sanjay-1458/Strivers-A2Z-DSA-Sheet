
bool canPartition(vector<int> &arr, int n)
{
	int sum=0;
	for(int i=0;i<n;++i) sum+=arr[i];
	if(sum%2!=0) return false;
	vector<vector<bool>> dp(n,vector<bool>(sum/2+1,false));
	for(int i=0;i<n;++i){
		dp[i][0]=true;
	}
	int k=sum/2;
	dp[0][arr[0]]=true;
	for(int i=1;i<n;++i){
		for(int j=1;j<=k;++j){
			bool nottake=dp[i-1][j];
			bool take=false;
			if(arr[i]<=j){
				take=dp[i-1][j-arr[i]];
			}
			dp[i][j]=take|nottake;
		}
	}
	return dp[n-1][k];
}
