class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int n = 1; n <= nums1.size(); n++) {
            for (int m = 1; m <= nums2.size(); m++) {
                if (nums1[n - 1] == nums2[m - 1]) {
                    dp[n][m] = 1 + dp[n - 1][m - 1];
                }
                else {
                    dp[n][m] = max(dp[n][m - 1], dp[n - 1][m]);
                }
            }
        }

        return dp[nums1.size()][nums2.size()];
    }
};
