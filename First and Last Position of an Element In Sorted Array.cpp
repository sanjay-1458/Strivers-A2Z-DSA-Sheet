class Solution {
    int p1(vector<int>&nums,int k){
        int ans=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int p2(vector<int>&nums,int k){
        int ans=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=p1(nums,target);
        int y=p2(nums,target);
        return {x,y};
    }
};
class Solution {
    int f(vector<int>&a,int x){
        int l=0,h=(int)a.size()-1;
        int ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==x){
                ans=m;
                h=m-1;
            }
            else if(a[m]<x){
                l=m+1;
            }
            else if(a[m]>x){
                h=m-1;
            }
        }
        return ans;
    }

    int lt(vector<int>&a,int x){
        int l=0,h=(int)a.size()-1;
        int ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==x){
                ans=m;
                l=m+1;
            }
            else if(a[m]<x){
                l=m+1;
            }
            else if(a[m]>x){
                h=m-1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int fr=f(nums,t);
        int ls=lt(nums,t);
        if(fr==-1) return {-1,-1};
        else return {fr,ls};
    }
};
