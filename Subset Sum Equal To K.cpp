#include <bits/stdc++.h> 


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1,vector<bool>(k+1,0));
    for(int j=0;j<n;++j){
        dp[j][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int i=1;i<n;++i){
        for(int j=1;j<k+1;++j){
            
            if(arr[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i]];
            }
        
        }
    }
    return dp[n-1][k];
}
