void fun(int n,int N,vector<string>& ans){
	if(n==N+1){
		return;
	}
	ans.push_back("Coding Ninjas");
	fun(n+1,N,ans);
}

vector<string> printNTimes(int n) {
	// Write your code here.
	vector<string> ans;
	fun(1,n,ans);
	return ans;
}
