class Solution {
public:

    int robHouses(vector<int>& nums, int i,vector<int>&dp) {
        if (i < 0) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int robCurrentHouse = nums[i] + robHouses(nums, i - 2,dp);
        int skipCurrentHouse = robHouses(nums, i - 1,dp);

        dp[i]= max(robCurrentHouse, skipCurrentHouse);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return robHouses(nums, nums.size() - 1,dp);
    }

};
