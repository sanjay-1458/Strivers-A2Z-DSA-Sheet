#include <bits/stdc++.h> 
int fun(int i,int j1,int j2,int r,int c,vector<vector<int>> &arr,vector<vector<vector<int>>>&dp){
    if(j1<0 || j1>=c){
        return -1e9;
    }
    if(j2<0 || j2>=c){
        return -1e9;
    }
    if(i==r-1){
        if(j1==j2){
            return arr[i][j1];
        }
        else{
            return arr[i][j1]+arr[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int sum=arr[i][j1];
    if(j1!=j2){
        sum+=arr[i][j2];
    }
    int ans=-1e9;
    for(int d1=-1;d1<=1;++d1){
        for(int d2=-1;d2<=1;++d2){
            int cnt=sum+fun(i+1,j1+d1,j2+d2,r,c,arr,dp);
            ans=max(ans,cnt);
        }
    }
    return dp[i][j1][j2]=ans;
}
int maximumChocolates(int r, int c, vector<vector<int>> &arr) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int>(c,-1)));
    return fun(0,0,c-1,r,c,arr,dp);
}




