int search(vector<int>& arr, int n, int target)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int ans=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>=arr[low]){
            if(target>=arr[low] && target<arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>arr[mid] && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return ans;
}
