class Solution {
public:

    int robHouses(vector<int>& nums, int i) {
        if (i < 0) {
            return 0;
        }

        int robCurrentHouse = nums[i] + robHouses(nums, i - 2);
        int skipCurrentHouse = robHouses(nums, i - 1);

        return max(robCurrentHouse, skipCurrentHouse);
    }
    
    int rob(vector<int>& nums) {
        return robHouses(nums, nums.size() - 1);
    }

};
