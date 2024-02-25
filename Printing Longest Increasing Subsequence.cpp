vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n,1),back(n,-1);
	int ans=0,ind=-1;
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			if(arr[j]<arr[i]){
				if(dp[j]+1>dp[i]){
					dp[i]=dp[j]+1;
					back[i]=j;
				}
			}
		}
		if(ans<dp[i]){
			ans=dp[i];
			ind=i;
		}
	}
	vector<int> t;
	while(ind>=0){
		t.push_back(arr[ind]);
		ind=back[ind];
	}
	reverse(t.begin(),t.end());
	return t;
}
