class Solution {
public: 
    int combination(vector<int>& nums, int target, vector<vector<int>>& memo){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        
        if(memo[nums.size()][target] != -1){
            return memo[nums.size()][target];
        }
        
        int count=0;
        for(int i=0;i<nums.size();i++){
            count += combination(nums, target - nums[i], memo);
        }
        
        memo[nums.size()][target] = count; 
        return count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(target + 1, -1));
        return combination(nums, target, memo);
    }
};
