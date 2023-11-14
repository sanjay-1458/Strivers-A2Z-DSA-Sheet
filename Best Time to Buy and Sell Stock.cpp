#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    vector<int> sell(n,0);
    sell[n-1]=prices[n-1];
    for(int i=n-2;i>=0;--i){
        sell[i]=max(prices[i],sell[i-1]);
    }
    vector<int> buy(n,0);
    buy[0]=sell[0];
    for(int i=1;i<n;++i){
        buy[i]=min(buy[i-1],prices[i]);
    }
    int ans=0;
    for(int i=0;i<n;++i){
        ans=max(ans,sell[i]-buy[i]);
    }
    return ans;
}
