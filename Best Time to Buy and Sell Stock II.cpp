#include<bits/stdc++.h>
long fun(int ind,long buy,long *arr,int n,vector<vector<long>> &dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy==0){
        return dp[ind][buy]=max(fun(ind+1,buy,arr,n,dp),-arr[ind]+fun(ind+1,1,arr,n,dp));
    }
    else{
        return dp[ind][buy]=max(arr[ind]+fun(ind+1,0,arr,n,dp),fun(ind+1,buy,arr,n,dp));
    }
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;--i){
        for(int j=1;j>=0;--j){
            if(j==0){
                dp[i][j]=max(dp[i+1][j],-values[i]+dp[i+1][1]);
            }
            else{
                dp[i][j]=max(values[i]+dp[i+1][0],dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}
