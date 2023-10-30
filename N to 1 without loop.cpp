void fun(int n,int N,vector<int>&ans){
    if(n==0) return;
    fun(n-1,N,ans);
    ans.push_back(N-n+1);
}

vector<int> printNos(int x) {
    vector<int> ans;
    fun(x,x,ans);
    return ans;
}


void fun(int n,int N,vector<int>&ans){
    if(n==N+1) return;
    fun(n+1,N,ans);
    ans.push_back(n);
}

vector<int> printNos(int x) {
    vector<int> ans;
    fun(1,x,ans);
    return ans;
}
