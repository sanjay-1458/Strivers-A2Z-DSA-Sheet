class Solution {
    int fun(int i,int j,string &s,string &t){
        if(i<0 && j<0){
            return 0;
        }
        if(i<0 && j>=0){
            return j+1;
        }
        if(j<0 && i>=0){
            return i+1;
        }
        if(s[i]==t[j]){
            return fun(i-1,j-1,s,t);
        }
        else{
            return 1+min(fun(i-1,j-1,s,t),min(fun(i-1,j,s,t),fun(i,j-1,s,t)));
        }
    }
public:
    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            dp[i][0]=i;
        }
        for(int j=1;j<=m;++j){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};
