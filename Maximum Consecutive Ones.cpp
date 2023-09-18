class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones=0,cnt=0;
        for(int i=0;i<nums.size();++i){
          if(nums[i]==0){
            cnt=0;
          }
          else{
            cnt++;
          }
          if(cnt>ones){
            ones=cnt;
          }
        }
        return ones;
    }
};
