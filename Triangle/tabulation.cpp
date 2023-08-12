class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        
        for (int col = 0; col < triangle.size(); col++) {
            dp[triangle.size() - 1][col] = triangle[triangle.size() - 1][col];
        }
        
        for (int row = triangle.size() - 2; row >= 0; row--) {
            for (int col = 0; col <= row; ++col) {
                dp[row][col] = triangle[row][col] + min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        return dp[0][0];
    }
};
