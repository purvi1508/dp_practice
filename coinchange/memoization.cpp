class Solution {
public:
    int change(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0;
        }
        
        if (n < 0 || amount < 0) {
            return 1e9;
        }
        
        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }
        
        int take = 1 + change(coins, amount - coins[n], n, dp);
        int notTake = change(coins, amount, n - 1, dp);
        
        dp[n][amount] = min(take, notTake);
        
        return dp[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int result = change(coins, amount, coins.size() - 1, dp);
        
        return result == 1e9 ? -1 : result;
    }
};
