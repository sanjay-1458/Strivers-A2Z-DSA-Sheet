int first(vector<int>& arr,int n,int x){
	int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==x){
			ans=mid;
			high=mid-1;
		}
		else if(arr[mid]>x){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}

int last(vector<int>& arr,int n,int x){
	int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==x){
			ans=mid;
			low=mid+1;
		}
		else if(arr[mid]<x){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return ans;
}

int count(vector<int>& arr, int n, int x) {
	int start=first(arr,n,x);
	int end=last(arr,n,x);
	int freq=end-start+1;
	if(end==-1){
		return 0;
	}
	return freq;
}
