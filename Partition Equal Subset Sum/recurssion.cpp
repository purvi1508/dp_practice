class Solution {
public:
    bool checkSubsetSum(vector<int>& nums, int totalSum, int i) {
        if (totalSum == 0) {
            return true;
        }
        if (i < 0 || totalSum < 0 || nums[i] > totalSum) {
            return false;
        }
        bool take = checkSubsetSum(nums, totalSum - nums[i], i - 1);
        bool nottake = checkSubsetSum(nums, totalSum, i - 1);
        return take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);

        if (totalSum % 2 != 0)
            return false;

        return checkSubsetSum(nums, totalSum / 2, nums.size() - 1);
    }
};
