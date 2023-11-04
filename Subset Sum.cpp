void fun(int ind,int sum,vector<int>&num,vector<int>&ans){
	if(ind>=num.size()){
		ans.push_back(sum);
		return;
	}
	sum+=num[ind];
	fun(ind+1,sum,num,ans);
	sum-=num[ind];
	fun(ind+1,sum,num,ans);
}


vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> ans;
	fun(0,0,num,ans);
	sort(ans.begin(),ans.end());
	return ans;
}
