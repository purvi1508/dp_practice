class Solution {
public:
    int robHouses(vector<int>& nums, int i,int check) {
        if (i < check) {
            return 0;
        }

        int robCurrentHouse = nums[i] + robHouses(nums, i - 2,check);
        int skipCurrentHouse = robHouses(nums, i - 1,check);

        return max(robCurrentHouse, skipCurrentHouse);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        int one=robHouses(nums, nums.size() - 2,0);
        int two=robHouses(nums, nums.size() - 1,1);
        return max(one,two);
    }
};
