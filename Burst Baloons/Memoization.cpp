class Solution {
public:
    int maxi(vector<int>& nums, int i, int j,vector<vector<int>>&memo) {
        if (i > j) {
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int maxCoins = 0;
        for (int k = i; k <= j; k++) {
            int leftValue = (i - 1 >= 0) ? nums[i - 1] : 1;
            int rightValue = (j + 1 < nums.size()) ? nums[j + 1] : 1;
            int coins = leftValue * nums[k] * rightValue;
            int leftCoins = maxi(nums, i, k - 1 , memo);
            int rightCoins = maxi(nums, k + 1, j , memo);
            maxCoins = max(maxCoins, coins + leftCoins + rightCoins);
        }
        memo[i][j]=maxCoins;
        return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>memo(n,vector<int>(n,-1));
        return maxi(nums, 0, n - 1,memo);
    }
};
