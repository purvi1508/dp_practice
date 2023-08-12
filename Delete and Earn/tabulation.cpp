class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_map<int, int> freq;
        int maxNum = 0;
        
        for (int num : nums) {
            freq[num]++;
            maxNum = max(maxNum, num);
        }
        
        vector<int> dp(maxNum + 1, 0);
        dp[1] = freq[1];

        for (int num = 2; num <= maxNum; ++num) {
            dp[num] = max(dp[num - 1], dp[num - 2] + num * freq[num]);
        }
        
        return dp[maxNum];
    }
};
