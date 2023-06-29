class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        if(nums.size()==1){
            return dp[0];
        }
         dp[1] = max(nums[0], nums[1]);
        if(nums.size()==2){
            return dp[1];
        }
        for(int i=2;i<nums.size();i++){
            int consider=nums[i]+dp[i-2];
            int notconsider=dp[i-1];
            dp[i]=max(consider,notconsider);
        }
        return dp[nums.size() - 1];
    }

};
