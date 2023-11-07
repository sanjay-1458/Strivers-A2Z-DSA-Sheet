const int mod=1e9+7;

int fun(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(arr[i][j]==-1){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int up=fun(i-1,j,arr,dp);
    int left=fun(i,j-1,arr,dp);
    return dp[i][j]=(up%mod+left%mod)%mod;
}


int mazeObstacles(int n, int m, vector< vector< int> > &arr) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return fun(n-1,m-1,arr,dp);
}


int mazeObstacles(int n, int m, vector< vector< int> > &arr) {
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0]=0;
    for(int i=1;i<m;++i){
        if(arr[0][i]!=-1) dp[0][i]=1;
        else break;
    }
    for(int i=0;i<n;++i){
        if(arr[i][0]!=-1) dp[i][0]=1;
        else break;
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            if(arr[i][j]==-1){
                dp[i][j]=0;
            }
            else{
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=(up%mod+left%mod)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
