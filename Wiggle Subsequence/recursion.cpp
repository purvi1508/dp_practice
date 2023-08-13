class Solution {
public:
    int counting(vector<int>& nums, int i, int prevDiff) {
        if (i == nums.size()) {
            return 0;
        }

        int consider = 0, not_consider = 0;

        if ((nums[i] - nums[i - 1] > 0 && prevDiff < 0) || (nums[i] - nums[i - 1] < 0 && prevDiff > 0)) {
            consider = 1 + counting(nums, i + 1, nums[i] - nums[i - 1]);
        }

        not_consider = counting(nums, i + 1, prevDiff);

        return max(consider, not_consider);
    }

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        return 1 + max(counting(nums, 1, nums[0]), counting(nums, 1, -nums[0]));
    }
};
