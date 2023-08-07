class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        
        // Base case: If the amount is 0, there is one combination (empty set)
        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 1;
        
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                // Number of combinations when considering the current coin
                int consider = 0;
                if (j >= coins[i - 1]) {
                    consider = dp[i][j - coins[i - 1]];
                }
                
                // Number of combinations when not considering the current coin
                int not_consider = dp[i - 1][j];
                
                dp[i][j] = consider + not_consider;
            }
        }
        
        return dp[coins.size()][amount];
    }
};
