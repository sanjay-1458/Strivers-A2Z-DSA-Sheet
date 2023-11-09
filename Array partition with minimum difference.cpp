
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int k=0;
	for(int i=0;i<n;++i) k+=arr[i];
	vector<int> prev(k+1,0);
	vector<int> curr(k+1,0);
	prev[0]=true;
	curr[0]=true;
    prev[arr[0]]=true;
    for(int i=1;i<n;++i){
        for(int j=1;j<=k;++j){
            bool nottake=prev[j],take=false;
            if(j-arr[i]>=0){
                take=prev[j-arr[i]];
            }
            curr[j]=take|nottake;
        }
		prev=curr;
    }
	int f1=0,f2=0;
	if(k%2==0 && prev[k/2]==true){
		return 0;
	}
	int ans=INT_MAX;
	
	for(int i=0;i<=k;++i){
		if(prev[i]!=0)
		ans=min(ans,abs(k-2*i));
	}
	return ans;
}
