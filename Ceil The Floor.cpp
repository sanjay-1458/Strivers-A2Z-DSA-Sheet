// Floor -> largest number in array <= x
// Ceil -> smallest number in array >= x

int floor(int arr[], int n,int target){
	int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==target){
			return arr[mid];
		}
		else if(arr[mid]<target){
			ans=arr[mid];
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return ans;
}

int ceil(int arr[],int n,int target){
	int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==target){
			return arr[mid];
		}
		else if(arr[mid]>target){
			ans=arr[mid];
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	sort(arr,arr+n);
	int ans1=floor(arr,n,x);
	int ans2=ceil(arr,n,x);
	pair<int,int> ans;
	ans.first=ans1;
	ans.second=ans2;
	return ans;
}
