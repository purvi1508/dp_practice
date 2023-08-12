class Solution {
public:
    int earnPoints(unordered_map<int, int>& freq, int num, int prevNum, vector<vector<int>>& memo) {
        if (num <= 0) {
            return 0;
        }
        
        if (memo[num][prevNum] != -1) {
            return memo[num][prevNum];
        }
        
        int pointsIfDeleted = earnPoints(freq, num - 2, num, memo) + num * freq[num];
        int pointsIfNotDeleted = earnPoints(freq, num - 1, prevNum, memo);
        
        memo[num][prevNum] = max(pointsIfDeleted, pointsIfNotDeleted);
        return memo[num][prevNum];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int maxNum = nums[nums.size() - 1];
        vector<vector<int>> memo(maxNum + 1, vector<int>(maxNum + 1, -1));
        
        return earnPoints(freq, maxNum, 0, memo);
    }
};
