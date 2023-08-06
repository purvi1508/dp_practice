class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Update the loop bounds, change i=n to i=n-1 to iterate from n-1 to 0.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                // Use proper variables to store the results of left and right values.
                int leftValue = (i - 1 >= 0) ? nums[i - 1] : 1;
                int rightValue = (j < n) ? nums[j] : 1;

                int maxCoins = 0;
                for (int k = i; k < j; k++) {
                    int coins = leftValue * nums[k] * rightValue;
                    int leftCoins = dp[i][k];
                    int rightCoins = dp[k + 1][j];
                    maxCoins = max(maxCoins, coins + leftCoins + rightCoins);
                }
                dp[i][j] = maxCoins;
            }
        }

        return dp[0][n];
    }
};
