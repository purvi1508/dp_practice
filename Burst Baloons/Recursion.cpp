class Solution {
public:
    int maxi(vector<int>& nums, int i, int j) {
        if (i > j) {
            return 0;
        }

        int maxCoins = 0;
        for (int k = i; k <= j; k++) {
            int leftValue = (i - 1 >= 0) ? nums[i - 1] : 1;
            int rightValue = (j + 1 < nums.size()) ? nums[j + 1] : 1;
            int coins = leftValue * nums[k] * rightValue;
            int leftCoins = maxi(nums, i, k - 1);
            int rightCoins = maxi(nums, k + 1, j);
            maxCoins = max(maxCoins, coins + leftCoins + rightCoins);
        }

        return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        return maxi(nums, 0, n - 1);
    }
};
