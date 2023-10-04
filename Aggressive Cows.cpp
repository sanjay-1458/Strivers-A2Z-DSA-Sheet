bool fun(vector<int>&arr,int cows,int dist){
    int prev=arr[0];
    int ans=1;
    for(int i=1;i<arr.size();++i){
        if(arr[i]-prev>=dist){
            prev=arr[i];
            ans++;
        }
        if(ans>=cows){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int mini=stalls[0],maxi=stalls[0];
    for(int i=0;i<stalls.size();++i){
        if(mini>stalls[i]){
            mini=stalls[i];
        }
        if(maxi<stalls[i]){
            maxi=stalls[i];
        }
    }
    sort(stalls.begin(),stalls.end());
    int low=0,high=maxi-mini;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(fun(stalls,k,mid)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
