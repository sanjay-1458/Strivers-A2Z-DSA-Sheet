void fun(int ind,vector<vector<int>>& result,vector<int>&nums,vector<int> temp){
    // if(ind>=nums.size()){
        result.push_back(temp);
        // return;
    // }
    for(int i=ind;i<nums.size();++i){
        if (i == ind || (nums[i] != nums[i - 1])) {
          temp.push_back(nums[i]);
          fun(i + 1, result, nums, temp);
          temp.pop_back();
        }
    }
}


vector<vector<int>> getUniqueSubsets(vector<int>& nums) {
    // Write Your Code Here    
    vector<vector<int>> ans;
    fun(0,ans,nums,{});
    sort(ans.begin(),ans.end());
    return ans;
}
