
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX); // Initialize DP array with maximum values
        dp[0] = 0; // Base case

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
