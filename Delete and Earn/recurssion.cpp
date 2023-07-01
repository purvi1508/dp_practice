class Solution {
public:
    int f(vector<int>& nums, int i, int restricted) {
        if (i == nums.size()) {
            return 0;
        }
        
        int pick = (nums[i]==restricted)?-1:nums[i]+f(nums, i+1,nums[i]+1);
        int notpick = f(nums, i+1, restricted);
        return max(pick, notpick);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return f(nums, 0, -1);
    }
};
