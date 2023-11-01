#include<bits/stdc++.h>
vector<int> countFrequency(int n, int x, vector<int> &nums){
    // Write your code here.
    vector<int> mp(max(x,n)+1,0);
    for(auto num:nums){
        mp[num]++;
    }
    vector<int> ans;
    for(int i=1;i<=n;++i){
        ans.push_back(mp[i]);
    }
    return ans;
}
