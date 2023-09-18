long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long gsum=0,curr=0;
    for(int i=0;i<n;++i){
        curr+=arr[i];
        gsum=max(gsum,curr);
        if(curr<0){
            curr=0;
        }
    }
    return gsum;
}
