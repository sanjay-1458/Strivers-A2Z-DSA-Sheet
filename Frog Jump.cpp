#include <bits/stdc++.h>

int fun(int n,vector<int>&arr,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n==1){
        return abs(arr[1]-arr[0]);
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=min(abs(arr[n]-arr[n-1])+fun(n-1,arr,dp),abs(arr[n]-arr[n-2])+fun(n-2,arr,dp));
}


int frogJump(int n, vector<int> &arr)
{
    vector<int> dp(n+1,-1);
    return fun(n-1,arr,dp);
}



int frogJump(int n, vector<int> &arr)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;++i){
        dp[i]=min(abs(arr[i]-arr[i-1])+dp[i-1],abs(arr[i]-arr[i-2])+dp[i-2]);
    }
    return dp[n-1];
}




int frogJump(int n, vector<int> &arr)
{
    vector<int> dp(n+1,-1);
    int prev2=0;
    int prev1=abs(arr[1]-arr[0]);
    for(int i=2;i<n;++i){
        int curr=min(abs(arr[i]-arr[i-1])+prev1,abs(arr[i]-arr[i-2])+prev2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
