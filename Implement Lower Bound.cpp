// Lower Bound = arr[i] >= x
// Lower Bound = lower_bound(arr.begin(),arr.end(),x) - arr.begin()

int lowerBound(vector<int> arr, int n, int x) {
	int l=0,h=n-1;
	while(l<=h){
		int m=(l+h)/2;
		if(arr[m]<x){
			l=m+1;
		}
		else{
			h=m-1;
		}
	}
	return l;
}
 
