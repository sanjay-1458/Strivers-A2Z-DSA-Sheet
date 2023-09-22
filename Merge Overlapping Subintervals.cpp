#include<vector>
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	int n=arr.size();
	for(int i=0;i<n-1;++i){
		int j=i+1;
		int el1=arr[i][1],el2=arr[j][0];
		if(el1>=el2){
			int m1=arr[i][0],m2=arr[j][1];
			arr[j][0]=m1;
			arr[j][1]=max(el1,m2);
			if(i==n-2){
				ans.push_back(arr[j]);
			}
		}
		else{
			ans.push_back(arr[i]);
			if(i==n-2){
				ans.push_back(arr[j]);
			}
		}
	}
	return ans;
}


#include<vector>
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	vector<vector<int>> ans;
	int n=arr.size();
	vector<int> vis(n,0);
	for(int i=0;i<n;++i){
		if(vis[i]==0){
			int el1=arr[i][0],el2=arr[i][1];
			vis[i]=1;
			for(int j=i+1;j<n;++j){
				int el3=arr[j][0],el4=arr[j][1];
				if(el2>=el3){
					el1=min(el1,el3);
					el2=max(el2,el4);
					vis[j]=1;
				}
			}
			ans.push_back({el1,el2});
		}
	}
	return ans;
}
