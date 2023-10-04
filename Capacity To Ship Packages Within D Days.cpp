int f(int mid,vector<int>&arr){
    int sum=0,cnt=1;
    for(int i=0;i<arr.size();++i){
        sum+=arr[i];
        if(sum>mid){
            cnt++;
            sum=arr[i];
        }
    }
    return cnt;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // sort(weights.begin(),weights.end());
    int maxi=weights[0],sum=0;
    for(int i=0;i<weights.size();++i){
        if(weights[i]>maxi){
            maxi=weights[i];
        }
        sum+=weights[i];
    }
    int low=maxi,high=sum,ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        int day=f(mid,weights);
        if(day<=d){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
