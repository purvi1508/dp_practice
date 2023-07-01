using namespace std;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> subarray(nums.begin() + i, nums.begin() + j + 1);
                    int sumi = accumulate(subarray.begin(), subarray.end(), 0);
                    int mini = *min_element(subarray.begin(), subarray.end());
                    maxi = max(maxi, sumi * mini);
            }
        }
        return maxi;
    }
};
