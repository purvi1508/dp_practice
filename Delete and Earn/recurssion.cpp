class Solution {
public:
    int earnPoints(unordered_map<int, int>& freq, int num) {
        if (num <= 0) {
            return 0;
        }
        
        int pointsIfDeleted = earnPoints(freq, num - 2) + num * freq[num];
        int pointsIfNotDeleted = earnPoints(freq, num - 1);
        
        return max(pointsIfDeleted, pointsIfNotDeleted);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        return earnPoints(freq,nums[nums.size()-1]);
    }
};
