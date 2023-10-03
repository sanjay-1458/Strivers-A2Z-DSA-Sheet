int floorSqrt(int n)
{
    long long int low=1,high=n;
    if(n==0) return 0;
    long long ans=0;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        else if(mid*mid<n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return (int)ans;
}
