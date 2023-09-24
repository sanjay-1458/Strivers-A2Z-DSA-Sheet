int search(vector<int> &nums, int target) {
    // Write your code here.
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int bs(vector<int>&arr,int low,int high,int target){
    if(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            return bs(arr,low,mid-1,target);
        }
        else{
            return bs(arr,mid+1,high,target);
        }
    }
    return -1;
}

int search(vector<int> &nums, int target) {
    int val=bs(nums,0,nums.size()-1,target);
    return val;
}
