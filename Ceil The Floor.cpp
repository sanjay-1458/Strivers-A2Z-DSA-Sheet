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


int floor(vector<int>&arr,int n,int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]<=x){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	if(high==-1) return -1;
	return arr[high];
}

int ceil(vector<int>&arr,int n,int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>=x){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	if(low==n) return -1;
	return arr[low];
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int p1=floor(a,n,x);
	int p2=ceil(a,n,x);
	pair<int,int> p={p1,p2};
	return p;
}
int f(vector<int> &a, int n, int x){
	int l=0,h=n-1;
	while(l<=h){
		int m=l+(h-l)/2;
		if(a[m]<=x){
			l=m+1;
		}
		else{
			h=m-1;
		}
	}
	return h==-1?-1:a[h];
}
int c(vector<int> &a, int n, int x){
	int l=0,h=n-1;
	while(l<=h){
		int m=(l+h)/2;
		if(a[m]<x){
			l=m+1;
		}
		else{
			h=m-1;
		}
	}
	return l==n?-1:a[l];
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int flr=f(a,n,x);
	int cel =c(a,n,x);
	return {flr,cel};
}
