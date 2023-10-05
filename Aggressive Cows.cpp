bool fun(vector<int>&arr, int dist,int cows){
    int cnt=1;
    int prev=arr[0];
    for(int i=1;i<arr.size();++i){
        if(arr[i]-prev>=dist){
            cnt++;
            prev=arr[i];
        }
        if(cnt>=cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(),arr.end());
    int maxi=arr[0],mini=arr[0];
    for(int i=0;i<arr.size();++i){
        if(maxi<arr[i]) maxi=arr[i];
        if(mini>arr[i]) mini=arr[i];
    }
    int low=0,high=maxi-mini;
    while(low<=high){
        int mid=low+(high-low)/2;//dist
        if(fun(arr,mid,k)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
