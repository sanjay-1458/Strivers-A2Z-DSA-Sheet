#include<bits/stdc++.h>

bool fun(int i,int j,string &s,string &t){
   if(i<0 && j<0){
      return true;
   }
   if(i<0 && j>=0){
      return false;
   }
   if(j<0 && i>=0){
      for(int k=0;k<=i;++k){
         if(s[k]!='*'){
            return false;
         }
      }
      return  true;
   }
   if(s[i]==t[j] || s[i]=='?'){
      return fun(i-1,j-1,s,t);
   }
   else{
      if(s[i]=='*'){
         return fun(i,j-1,s,t) || fun(i-1,j,s,t);
      }
      else{
         return false;
      }
   }
}

bool wildcardMatching(string s, string t)
{
   int n=s.size(),m=t.size();
   vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
   dp[0][0]=true;
   for(int j=1;j<=m;++j){
      dp[0][j]=false;
   }
   for(int i=1;i<=n;++i){
      if(s[i-1]=='*'){
         dp[i][0]=true;
      }
      else{
         break;
      }
   }
   for(int i=1;i<=n;++i){
      for(int j=1;j<=m;++j){
         if(s[i-1]==t[j-1] || s[i-1]=='?'){
            dp[i][j]=dp[i-1][j-1];
         }
         else{
            if(s[i-1]=='*'){
               dp[i][j]=dp[i][j-1] || dp[i-1][j];
            }
            else{
               dp[i][j]=false;
            }
         }
      }
   }
   return  dp[n][m];
}
