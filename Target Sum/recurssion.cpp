class Solution {
public:
    int targetsum(vector<int>& nums, int target,int i){
        if (i < 0) {
            if (target == 0) {
                return 1;  
            } else {
                return 0;  
            }
        }
        int sumpos=targetsum(nums,target-nums[i],i-1);
        int sumneg=targetsum(nums,target+nums[i],i-1);
        return sumpos+sumneg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetsum(nums,target,nums.size()-1);
    }
};
