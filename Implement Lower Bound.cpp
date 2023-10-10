// Lower Bound = arr[i] >= x
// Lower Bound = lower_bound(arr.begin(),arr.end(),x) - arr.begin()

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]<x){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return low;
}

 
