// Upper Bound = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
// Upper Bound = arr[i] > x;

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int low=0,high=n-1;
	int ans=n;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]<=x){
			low=mid+1;
		}
		else{
			ans=mid;
			high=mid-1;
		}
	}
	return ans;
}
