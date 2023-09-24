int lowerBound(vector<int> arr, int n, int target) {
	// Write your code here
	int low=0,high=n-1,val=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==target){
			val=mid;
			high=mid-1;
		}
		else if(arr[mid]>target){
			val=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	if(val==-1){
		val=low;
	}
	return val;
}
 
