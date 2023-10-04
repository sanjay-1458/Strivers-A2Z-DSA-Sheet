int f(vector<int>&arr,long long mid,int k){
	int ans=0,cnt=k;
	for(int i=0;i<arr.size();++i){
		if(arr[i]<=mid){
			cnt--;
		}
		else{
			cnt=k;
		}
		if(cnt==0){
			ans++;
			cnt=k;
		}
	}
	return ans;
}

int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int ans=-1;
	int maxi=arr[0];
	for(int i=0;i<arr.size();++i){
		if(arr[i]>maxi){
			maxi=arr[i];
		}
	}
	long long int low=1,high=maxi;
	while(low<=high){
		long long mid=low+(high-low)/2;
		int cnt=f(arr,mid,k);
		if(cnt==0){
			low=mid+1;
		}
		else if(cnt>=m){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}
