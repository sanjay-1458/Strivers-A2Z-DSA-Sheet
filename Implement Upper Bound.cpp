// Upper Bound = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
// Upper Bound = arr[i] > x;

int upperBound(vector<int> &arr, int x, int n){
	int l=0,h=n-1;
	while(l<=h){
		int m=(l+h)/2;
		if(arr[m]<=x){
			l=m+1;
		}
		else{
			h=m-1;
		}
	}
	return l;
}
