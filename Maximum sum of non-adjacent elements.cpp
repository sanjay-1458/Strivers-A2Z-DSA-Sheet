#include <bits/stdc++.h> 

int fun(int ind,vector<int>&nums){
    if(ind<0) return 0;
    int notpick=fun(ind-1,nums);
    int pick=nums[ind]+fun(ind-2,nums);
    return max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    return fun(nums.size()-1,nums);
}


int fun(int ind,vector<int>&nums,vector<int>&dp){
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int notpick=fun(ind-1,nums,dp);
    int pick=nums[ind]+fun(ind-2,nums,dp);
    return dp[ind]=max(pick,notpick);
}



int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    dp[0]=nums[0];
    for(int i=1;i<nums.size();++i){
        if(i==1)
        dp[i]=max(nums[0],nums[1]);
        else{
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
    }
    return dp[nums.size()-1];
}
