class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int val=n;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            if(nums[i]!=i){
                val=i;
                break;
            }
        }
        return val;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int _xor=0;
        for(int i=1;i<=n;++i){
            _xor=_xor^i;
        }
        for(int i=0;i<n;++i){
            _xor=_xor^nums[i];
        }
        return _xor;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=1;i<=n;++i){
            sum+=i;
        }
        for(int i=0;i<n;++i){
            sum-=nums[i];
        }
        return sum;
    }
};
