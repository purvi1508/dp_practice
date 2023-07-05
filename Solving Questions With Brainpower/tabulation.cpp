class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            long long accept = questions[i][0] + (i + questions[i][1] + 1 < n ? dp[i + questions[i][1] + 1] : 0);
            long long not_accept = (i + 1 < n ? dp[i + 1] : 0);
            dp[i] = max(accept, not_accept);
        }

        return dp[0];
    }
};
