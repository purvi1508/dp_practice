class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProduct = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int prevMax = currMax;
            currMax = max(max(prevMax * nums[i], currMin * nums[i]), nums[i]);
            currMin = min(min(prevMax * nums[i], currMin * nums[i]), nums[i]);
            maxProduct = max(maxProduct, currMax);
        }

        return maxProduct;
    }
};
