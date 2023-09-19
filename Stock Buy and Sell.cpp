int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int profit=0,n=prices.size();
    for(int i=0;i<n;++i){
        int buy=prices[i];
        for(int j=i;j<n;++j){
            int sell=prices[j];
            int newProfit=sell-buy;
            if(profit<newProfit){
                profit=newProfit;
            }
        }
    }
    return profit;
}


int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int profit=0,n=prices.size();
    vector<int> buy(n),sell(n);
    buy[0]=prices[0];sell[n-1]=prices[n-1];
    for(int i=1;i<n;++i){
        buy[i]=min(buy[i-1],prices[i]);
        sell[n-1-i]=max(sell[n-i],prices[n-1-i]);
    }
    for(int i=0;i<n;++i){
        profit=max(profit,sell[i]-buy[i]);
    }
    return profit;
}
