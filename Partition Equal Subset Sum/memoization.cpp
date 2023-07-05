class Solution {
public:
    bool checkSubsetSum(vector<int>& nums, int targetSum, int i, vector<vector<int>>& dp) {
        if (targetSum == 0) {
            return true;
        }
        if (i < 0 || targetSum < 0) {
            return false;
        }
        if (dp[i][targetSum] != -1) {
            return dp[i][targetSum];
        }
        bool take = false, nottake = false;
        if (nums[i] <= targetSum) {
            take = checkSubsetSum(nums, targetSum - nums[i], i - 1, dp);
        }
        nottake = checkSubsetSum(nums, targetSum, i - 1, dp);

        dp[i][targetSum] = take || nottake;
        return dp[i][targetSum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);
        
        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));

        if (checkSubsetSum(nums, targetSum, n - 1, dp) == false) {
            return false;
        }
        return true;
    }
};
