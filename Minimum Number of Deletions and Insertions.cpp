int fun(int i,int j,string s,string t,vector<vector<int>>&dp){
    if(j==0 && i>=1){
        return i;
    }
    if(i==0 && j>=1){
        return j;
    }
    if(i==0 && j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i-1]==t[j-1]){
        return dp[i][j]=fun(i-1,j-1,s,t,dp);
    }
    else{
        return dp[i][j]=1+min(fun(i-1,j,s,t,dp),fun(i,j-1,s,t,dp));
    }
}

int canYouMake1(string &s1, string &s2){
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return fun(n,m,s1,s2,dp);
}
int canYouMake2(string &s1, string &s2){
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i){
        dp[i][0]=i;
    }
    for(int j=1;j<=m;++j){
        dp[0][j]=j;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int canYouMake(string &s1, string &s2){
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;++i){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;++j){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int d1=n-dp[n][m];
    int d2=m-dp[n][m];
    return d1+d2;
}
