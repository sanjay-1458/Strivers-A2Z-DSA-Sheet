#include <bits/stdc++.h> 

bool palindrome(string &s){
    int low=0,high=s.size()-1;
    while(low<high){
        if(s[low]!=s[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int fun(int ind,string s){
    if(ind<0){
        if(palindrome(s)){
            return s.size();
        }
        else{
            return 0;
        }
    }
    int take=fun(ind-1,s);
    s.erase(s.begin()+ind);
    int nottake=fun(ind-1,s);
    return max(take,nottake);
}

int longestPalindromeSubsequence(string s)
{
    int n=s.size();
    int m=n;
    string t=s;
    reverse(t.begin(),t.end());
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;++j){
        dp[0][j]=0;
    }
    for(int i=0;i<=n;++i){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
