class Solution {
public:
    int minCoststart0(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) {
            return 0;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        int left = cost[i] + minCoststart0(cost, i + 1, dp);
        int right = cost[i] + minCoststart0(cost, i + 2, dp);
        
        dp[i] = min(left, right);
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        int check0 = minCoststart0(cost, 0, dp);
        vector<int> dp2(cost.size(), -1);
        int check1 = minCoststart0(cost, 1, dp2);
        return min(check0, check1);
    }
};
