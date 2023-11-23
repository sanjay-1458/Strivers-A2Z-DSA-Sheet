#include <bits/stdc++.h> 
long long maximumNonAdjacentSum(vector<long long> &arr){

    long long n=arr.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    vector<long long> dp(n+1,0);
    long long prev2=0;
    long long prev1=arr[0];
    for(long long i=2;i<=n;++i){
        long long exclude=prev1;
        long long include=arr[i-1]+prev2;
        long long curr=max(include,exclude);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;;
}
long long int houseRobber(vector<int>& arr)
{
    int n=arr.size();
    vector<long long> temp1,temp2;
    if(n==1){
        return arr[0];
    }
    for(int i=0;i<n;++i){
        if(i!=0)
        temp1.push_back(arr[i]);
        if(i!=n-1)
        temp2.push_back(arr[i]);
    } 
    long long ans1=maximumNonAdjacentSum(temp1);
    long long ans2=maximumNonAdjacentSum(temp2);
    return max(ans1,ans2);
 
}
