#include <bits/stdc++.h> 

int fun(int ind,int sum,vector<int>&nums){
    if(sum==0) return 0;
    if(ind==0){
        if(nums[0]%sum==0){
            return nums[0]/sum;
        }
        else{
            return 10005;
        }
    }
    int exclude=fun(ind-1,sum,nums);
    int include=10005;
    if(sum-nums[ind]>=0){
        include=1+fun(ind,sum-nums[ind],nums);
    }
    return min(include,exclude);

}

int minimumElements(vector<int> &nums, int x)
{

    vector<vector<int>> dp(nums.size()+1,vector<int>(x+1,10005));
    for(int i=0;i<nums.size();++i){
        dp[i][0]=0;
    }
    for(int j=0;j<=x;++j){
        if(j%nums[0]==0){
            dp[0][j]=j/nums[0];
        }
        else{
            dp[0][j]=10005;
        }
    }
    for(int i=1;i<nums.size();++i){
        for(int j=1;j<=x;++j){
            int exclude=dp[i-1][j];
            int include=10005;
            if(j-nums[i]>=0){
                include=1+dp[i][j-nums[i]];
            }
            dp[i][j]=min(include,exclude);
        }
    }
    if(dp[nums.size()-1][x]>=10005){
        return -1;
    }
    else{
        return dp[nums.size()-1][x];
    }
}
