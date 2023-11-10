
long fun(int ind,int sum,int *arr){
    if(sum==0){
        return 1;
    }
    if(ind==0){
        if(arr[0]==sum){
            return 1;
        }
        if(sum%arr[0]==0){
            return 1;
        }
        return 0;
    }
    long exclude=fun(ind-1,sum,arr);
    long include=0;
    if(sum-arr[ind]>=0)
    include=fun(ind,sum-arr[ind],arr);
    return include+exclude;
}

long countWaysToMakeChange(int *arr, int n, int sum)
{
    long dp[n+1][sum+1]={0};
    for(int i=0;i<n;++i){
        dp[i][0]=1;
    }
    for(int j=0;j<=sum;++j){
        if(arr[0]==j){
            dp[0][arr[0]]=1;
        }
        else if(j%arr[0]==0){
            dp[0][j]=1;
        }
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<=sum;++j){
            long exclude=dp[i-1][j];
            long include=0;
            if(j-arr[i]>=0){
                include=dp[i][j-arr[i]];
            }
            dp[i][j]=include+exclude;
        }
    }
    return dp[n-1][sum];
}
