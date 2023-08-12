class Solution {
public: 
    int combination(vector<int>& nums, int target){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=combination(nums,target-nums[i]);
        }
        return count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return combination(nums,target);
    }
};
