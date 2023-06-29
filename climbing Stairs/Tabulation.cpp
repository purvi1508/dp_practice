class Solution {
public:
    int climbStairscheck(int n, vector<int>& dp) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int left = climbStairscheck(n - 1, dp);
        int right = climbStairscheck(n - 2, dp);
        dp[n] = left + right;
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climbStairscheck(n, dp);
    }
};
