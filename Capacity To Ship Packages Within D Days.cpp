int fun(vector<int>&arr, int w){
    int sum=arr[0],cnt=1;
    for(int i=1;i<arr.size();++i){
        if(sum+arr[i]>w){
            cnt++;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    return cnt;
}

int leastWeightCapacity(vector<int> &arr, int d)
{
    // Write your code here.
    int maxi=arr[0],sum=0;
    for(int i=0;i<arr.size();++i){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
        sum+=arr[i];
    }
    int low=maxi,high=sum,ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;//capacity
        int day=fun(arr,mid);
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
