#include <bits/stdc++.h> 

int mod=(int)(1e9+7);
int fun(int ind,int sum,vector<int>&arr,vector<vector<int>>& dp){
    if(ind==0){
        if(arr[0]==0 && sum==0){
            return 2;
        }
        if(arr[0]==sum || sum==0) return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int take=0,nottake=0;
    nottake=fun(ind-1,sum,arr,dp);
    if(arr[ind]<=sum){
        take=fun(ind-1,sum-arr[ind],arr,dp);
    }
    return dp[ind][sum]=(take%mod+nottake%mod)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(int i=0;i<n;++i) sum+=arr[i];
    int target=(sum+d)/2;
    if((sum+d)%2!=0) return 0;
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]<=target && arr[0]!=0){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<=target;++j){
            int take=0,nottake=0;
            nottake=dp[i-1][j];
            if(j-arr[i]>=0){
                take=(dp[i-1][j-arr[i]]);
            }
            dp[i][j]=(take%mod+nottake%mod)%mod;
        }
    }
    return dp[n-1][target];

}


