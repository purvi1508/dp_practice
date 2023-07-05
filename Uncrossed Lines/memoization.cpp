class Solution {
public:
    int maxcount(vector<int>& nums1, vector<int>& nums2, int n, int m,vector<vector<int>>&dp) {
        if (m < 0 || n < 0) {
            return 0;
        }
        if (nums1[n] == nums2[m]) {
            return 1 + maxcount(nums1, nums2, n - 1, m - 1,dp);
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        else {
            int case1 = maxcount(nums1, nums2, n, m - 1,dp);
            int case2 = maxcount(nums1, nums2, n - 1, m - 1,dp);
            int case3 = maxcount(nums1, nums2, n - 1, m,dp);
            dp[n][m]= max(case1, max(case2, case3));
            return dp[n][m];
        }
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        return maxcount(nums1, nums2, nums1.size() - 1, nums2.size() - 1,dp);
    }
};
