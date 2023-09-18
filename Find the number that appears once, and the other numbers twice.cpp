#include<bits/stdc++.h>
int getSingleElement(vector<int> &arr){
	// Write your code here.
	int n=arr.size();
	map<int,int> mp;
	for(int i=0;i<n;++i){
		mp[arr[i]]++;
	}
	int val=arr[0];
	for(auto e:mp){
		if(e.second==1){
			val=e.first;
		}
	}
	return val;
}

#include<bits/stdc++.h>
int getSingleElement(vector<int> &arr){
	// Write your code here.
	int n=arr.size();
	int _xor=0;
	for(int i=0;i<n;++i){
		_xor=_xor^arr[i];
	}
	return _xor;
}



#include<bits/stdc++.h>
int bs(vector<int>arr){
	int low=0,high=arr.size()-1;
	while(low<=high){
		int mid=(low+high)/2;
		int first,second;
		if(arr[mid]==arr[mid+1]){
			first=mid;
			second=mid+1;
		}
		else if(arr[mid]==arr[mid-1]){
			first=mid-1;
			second=mid;
		}
		else{
			return arr[mid];
		}
		if(first%2==0){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
}
int getSingleElement(vector<int> &arr){
	// Write your code here.
	int n=arr.size();
	if(n==1){
		return arr[0];
	}
	return bs(arr);
}
