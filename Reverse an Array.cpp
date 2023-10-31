void fun(int low,int high,vector<int>&nums){
    if(low<high){
        swap(nums[low],nums[high]);
        fun(low+1,high-1,nums);
    }
    return;
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    int low=0,high=n-1;
    fun(low,high,nums);
    return nums;
}
