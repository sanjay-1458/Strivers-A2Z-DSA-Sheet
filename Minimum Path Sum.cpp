#include <bits/stdc++.h> 

int fun(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
    if(i==0 && j==0) return arr[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=arr[i][j]+fun(i-1,j,arr,dp);
    int left=arr[i][j]+fun(i,j-1,arr,dp);
    return dp[i][j]=min(up,left);
}

int minSumPath(vector<vector<int>> &arr) {
    int n=arr.size(),m=arr[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return fun(n-1,m-1,arr,dp);
}


int minSumPath(vector<vector<int>> &arr) {
    int n=arr.size(),m=arr[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i==0 && j==0) dp[i][j]=arr[i][j];
            else{
                int up=1e9,left=1e9;
                if(i>0){
                    up=arr[i][j]+dp[i-1][j];
                }
                if(j>0){
                    left=arr[i][j]+dp[i][j-1];
                }
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}
