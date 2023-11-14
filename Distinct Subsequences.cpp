int fun(int i,int j,string &s,string &t){
      if(j<0){
            return 1;
      }
      if(i<0){
            return 0;
      }
      int take=0,nottake=0;
      if(s[i]==t[j]){
            take=fun(i-1,j-1,s,t);
            nottake=fun(i-1,j,s,t);
      }
      else{
            nottake=fun(i-1,j,s,t);
      }
      return take+nottake;
      
}

int distinctSubsequences(string &str, string &sub)
{
      int n=str.size(),m=sub.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      for(int j=0;j<=m;++j){
            dp[0][j]=0;
      }
      for(int i=0;i<=n;++i){
            dp[i][0]=1;
      }
      const int mod=1e9+7;
      for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                  if(str[i-1]==sub[j-1]){
                        dp[i][j]= (dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
                  }
                  else{
                        dp[i][j]= (dp[i-1][j])%mod;
                  }
            }
      }
	return dp[n][m];
}
