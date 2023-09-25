int findKRotation(vector<int> &arr){
    // Write your code here.  
    int n=arr.size(),ans=-1;
    int low=0,high=n-1;  
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid!=0 && mid !=n-1 &&(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1])){
            ans=mid;
            break;
        }
        else if(arr[low]<=arr[mid]){
            if(arr[low]>arr[high]){
                low=mid+1;
            }
            else{
                ans=low;
                break;
            }
        }
        else{
            if(arr[low]>=arr[mid]){
                high=mid-1;
            }
            else{
                ans=low;
                break;
            }
        }
    }
    return ans;
}
