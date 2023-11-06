int fun(int ind,int k,vector<int>&arr,vector<int>&dp){
    if(ind==0) return 0;
    int ans=INT_MAX;
    if(dp[ind]!=-1) return dp[ind];
    for(int i=1;i<=k;++i){
        int loss=INT_MAX;
        if(ind-i>=0)
            loss=abs(arr[ind]-arr[ind-i])+fun(ind-i,k,arr,dp);
        ans=min(ans,loss);
    }
    return dp[ind]=ans;
}

int minimizeCost(int n, int k, vector<int> &arr){
    vector<int> dp(n,-1);
    return fun(n-1,k,arr,dp);
}
