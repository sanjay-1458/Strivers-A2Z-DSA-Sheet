int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int mini=v[0],maxi=v[0];
    for(int i=0;i<v.size();++i){
        if(v[i]>maxi){
            maxi=v[i];
        }
        if(v[i]<mini){
            mini=v[i];
        }
    }
    long long int low=1,high=maxi;
    int ans=low;
    while(low<=high){
        long long mid=low+(high-low)/2;
        long long int cnt=0;
        for(int i=0;i<v.size();++i){
            if(v[i]%mid==0){
                cnt+=v[i]/mid;
            }
            else{
                cnt+=v[i]/mid+1;
            }
        }
        if(cnt==h){
            ans=mid;
            high=mid-1;
        }
        else if(cnt<h){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
