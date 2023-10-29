#include <bits/stdc++.h>
int fun(int n){
    if(n==0){
        return true;
    }
    if(n<0){
        return false;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int path1=fun(n-1);
    int path2=fun(n-2);
    return dp[n]=(path1+path2)%1000000007;
}
int countDistinctWays(int n) {
    //  Write your code here.
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
    }
    return dp[n];
}
