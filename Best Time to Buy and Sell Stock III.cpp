int fun(int ind,int buy,vector<int>&prices){
    if(ind>=prices.size() || buy<=0){
        return 0;
    }
    if(buy==4){
        return max(fun(ind+1,buy,prices),-prices[ind]+fun(ind+1,buy-1,prices));
    }
    else if(buy==3){
        return max(fun(ind+1,buy,prices),prices[ind]+fun(ind+1,buy-1,prices));
    }
    else if(buy==2){
        return max(fun(ind+1,buy,prices),-prices[ind]+fun(ind+1,buy-1,prices));
    }
    else{
        return max(fun(ind+1,buy,prices),prices[ind]+fun(ind+1,buy-1,prices));
    }
}

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    for(int i=0;i<=4;++i){
        dp[n][i]=0;
    }
    for(int i=0;i<=n;++i){
        dp[i][0]=0;
    }
    for(int i=n-1;i>=0;--i){
        for(int j=1;j<=4;++j){
            if(j==4){
                dp[i][j]= max(dp[i+1][j],-prices[i]+dp[i+1][j-1]);
            }
            else if(j==3){
                dp[i][j]= max(dp[i+1][j],prices[i]+dp[i+1][j-1]);
            }
            else if(j==2){
                dp[i][j]= max(dp[i+1][j],-prices[i]+dp[i+1][j-1]);
            }
            else{
                dp[i][j]= max(dp[i+1][j],prices[i]+dp[i+1][j-1]);
            }
        }
    }
    return dp[0][4];
}
