class Solution {
public:
    int maxi(vector<int>& prices, int i, int j, int n, vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int profit;
        if (j == 0) {
            profit = max((-prices[i] + maxi(prices, i + 1, 1, n, dp)), maxi(prices, i + 1, 0, n, dp));
        }
        else {
            profit = max((prices[i] + maxi(prices, i + 1, 0, n, dp)), maxi(prices, i + 1, 1, n, dp));
        }
        dp[i][j] = profit;
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxi(prices, 0, 0, n, dp);
    }
};
