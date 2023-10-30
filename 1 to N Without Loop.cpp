void fun(vector<int>&ans,int n,int N){
    if(n==N+1){
        return;
    }
    ans.push_back(n);
    fun(ans,n+1,N);
}

vector<int> printNos(int x) {
    // Write Your Code Here
    vector<int> ans;
    fun(ans,1,x);
    return ans;
}
