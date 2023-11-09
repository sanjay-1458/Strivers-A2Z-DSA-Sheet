#include <bits/stdc++.h> 



int getMaxPathSum(vector<vector<int>> &arr)
{
    int n=arr.size(),m=arr[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int res=-1e5;
    vector<int> prev(m,0),temp(m,0);
    for(int j=0;j<m;++j){
        prev[j]=arr[0][j];
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<m;++j){
            int up=-1e8,left=-1e8,right=-1e8;
            up=arr[i][j]+prev[j];
            if(j-1>=0){
                left=arr[i][j]+prev[j-1];
            }
            if(j+1<m){
                right=arr[i][j]+prev[j+1];
            }
            temp[j]=max(up,max(left,right));
        }
        prev=temp;
    }
    res=-1e8;
    for(int j=0;j<m;++j){
        res=max(res,prev[j]);
    }
    return res;
}
