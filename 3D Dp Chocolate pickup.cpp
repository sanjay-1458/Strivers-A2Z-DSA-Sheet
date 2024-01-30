#include <bits/stdc++.h> 

int fun(int r,int c1,int c2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    int n=grid.size();
    int m=grid[0].size();
    if(c1<0 || c2<0 || c1>=m || c2>=m){
        return -1e7;
    }
    if(r==n-1){
        if(c1!=c2){
            return grid[r][c1]+grid[r][c2];
        }
        else{
            return grid[r][c1];
        }
    }
    if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
    int a=0;
    for(int i=-1;i<=1;++i){
        for(int j=-1;j<=1;++j){
            int z=grid[r][c2];
            if(c1==c2) z=0;
            a=max(fun(r+1,c1+i,c2+j,grid,dp)+grid[r][c1]+z,a);
        }
    }
    return dp[r][c1][c2]=a;
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return fun(0,0,m-1,grid,dp);
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int c1=0;c1<m;++c1){
        for(int c2=0;c2<m;++c2){
            if(c1==c2){
                dp[n-1][c1][c2]=grid[n-1][c1];
            }
            else{
                dp[n-1][c1][c2]=grid[n-1][c1]+grid[n-1][c2];
            }
        }
    }
    for(int r=n-2;r>=0;--r){
        for(int c1=0;c1<m;++c1){
            for(int c2=0;c2<m;++c2){
                int maxi=INT_MIN;
                for(int i=-1;i<=1;++i){
                    for(int j=-1;j<=1;++j){
                        int ans=0;
                        if(c1==c2){
                            ans=grid[r][c1];
                        }
                        else{
                            ans=grid[r][c1]+grid[r][c2];
                        }
                        if(c1+i<0 || c1+i>=m || c2+j<0 || c2+j>=m){
                            ans+=-1e5;
                        }
                        else{
                            ans+=dp[r+1][c1+i][c2+j];
                        }
                        maxi=max(maxi,ans);
                   }
                }
                dp[r][c1][c2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
    
}
