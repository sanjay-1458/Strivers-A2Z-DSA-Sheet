int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int res=0;
    int i=0,j=0,n=a.size();
    long long sum=0;
    while(j<n){
        sum+=a[j];
        if(sum<k){
            j++;
        }
        else if(sum==k){
            res=max(res,j-i+1);
            j++;
        }
        else{
            while(sum>k){
                sum-=a[i];
                i++;
            }
            if(sum==k){
                res=max(res,j-i+1);
            }
            j++;
        }
    }
    return res;
}
