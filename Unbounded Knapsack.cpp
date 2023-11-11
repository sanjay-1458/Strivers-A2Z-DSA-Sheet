int fun(int ind,int W,vector<int>& profit,vector<int>&wt){

    if(W==0){
        return 0;
    }
    if(ind==0){
        if(W%wt[ind]==0){
            return (W/wt[ind])*profit[0];
        }
        else{
            return 0;
        }
    }
    int exclude=fun(ind-1,W,profit,wt);
    int include=0;
    if(W-wt[ind]>=0){
        include=profit[ind]+fun(ind,W-wt[ind],profit,wt);
    }
    return max(include,exclude);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &wt){
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=0;i<n;++i){
        dp[i][0]=0;
    }
    for(int j=0;j<=w;++j){
        if(j%wt[0]==0){
            dp[0][j]=(j/wt[0])*profit[0];
        }
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<=w;++j){
            int exclude=dp[i-1][j],include=0;
            if(j-wt[i]>=0){
                include=profit[i]+dp[i][j-wt[i]];
            }
            dp[i][j]=max(include,exclude);
        }
    }
    return dp[n-1][w];
}
