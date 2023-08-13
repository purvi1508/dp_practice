class Solution {
public:
    int counting(vector<int>& nums, int i, int prevDiff, vector<vector<int>>& memo) {
        if (i == nums.size()) {
            return 0;
        }

        if (memo[i][prevDiff + 1000] != -1) {
            return memo[i][prevDiff + 1000];
        }

        int consider = 0, not_consider = 0;

        if ((nums[i] - nums[i - 1] > 0 && prevDiff < 0) || (nums[i] - nums[i - 1] < 0 && prevDiff > 0)) {
            consider = 1 + counting(nums, i + 1, nums[i] - nums[i - 1], memo);
        }

        not_consider = counting(nums, i + 1, prevDiff, memo);

        memo[i][prevDiff + 1000] = max(consider, not_consider);
        return memo[i][prevDiff + 1000];
    }

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        vector<vector<int>> memo(nums.size(), vector<int>(2001, -1));
        return 1 + max(counting(nums, 1, nums[0], memo), counting(nums, 1, -nums[0], memo));
    }
};
