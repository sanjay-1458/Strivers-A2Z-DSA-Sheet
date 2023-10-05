int fun(vector<int>&arr,int k){
    int sum=arr[0],cnt=1;
    for(int i=1;i<arr.size();++i){
        if(sum+arr[i]<=k){
            sum+=arr[i];
        }
        else{
            sum=arr[i];
            cnt++;
        }
    }
    return cnt;
}

int findLargestMinDistance(vector<int> &arr, int k)
{
    int maxi=arr[0],sum=0;
    for(int i=0;i<arr.size();++i){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
        sum+=arr[i];
    }
    int low=maxi,high=sum;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=fun(arr,mid);
        if(cnt>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
