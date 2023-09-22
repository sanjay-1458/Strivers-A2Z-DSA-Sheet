#include<vector>
int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int ans=1,curr=1,n=arr.size();
	for(int i=0;i<n;++i){
		curr=curr*arr[i];
		ans=max(ans,curr);
		if(curr==0){
			curr=1;
		}
	}
	curr=1;
	for(int i=n-1;i>=0;--i){
		curr=curr*arr[i];
		ans=max(curr,ans);
		if(curr==0){
			curr=1;
		}
	}
	return ans;
}
