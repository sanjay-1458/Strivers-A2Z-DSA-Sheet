int maxMoneyLooted(vector<int> &arr, int n)
{
	int prev2=0;
	int prev1=arr[0];
	for(int i=2;i<=n;++i){
		int take=arr[i-1]+prev2;
		int nottake=prev1;
		int curr=max(take,nottake);
		prev2=prev1;
		prev1=curr;
	}
	return prev1;
}
