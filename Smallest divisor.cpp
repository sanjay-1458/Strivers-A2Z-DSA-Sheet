long long f(vector<int>&arr,long long mid){
	long long sum=0;
	for(int i=0;i<arr.size();++i){
		if(arr[i]%mid==0){
			sum+=arr[i]/mid;
		}
		else{
			sum+=arr[i]/mid+1;
		}
	}
	return sum;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	int maxi=arr[0];
	for(int i=0;i<arr.size();++i){
		if(arr[i]>maxi){
			maxi=arr[i];
		}
	}
	long long low=1,high=maxi;
	int ans=maxi;
	while(low<=high){
		long long mid=low+(high-low)/2;
		long long sum=f(arr,mid);
		if(sum>limit){
			low=mid+1;
		}
		else{
			ans=mid;
			high=mid-1;
		}
	}
	return ans;
}
