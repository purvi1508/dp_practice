
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Calculate prefix sums
        vector<long long> prefixSum(n + 1,0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // Calculate the next smaller element to the left for each element
        vector<int> prevSmaller(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.empty()==false && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()==false) {
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        // Calculate the next smaller element to the right for each element
        vector<int> nextSmaller(n, n);
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        // Calculate the maximum sum of minimum products
        long long maxSumMinProduct = 0;
        for (int i = 0; i < n; i++) {
            long long sum = prefixSum[nextSmaller[i]] - prefixSum[prevSmaller[i] + 1];
            maxSumMinProduct = max(maxSumMinProduct, sum * nums[i]);
        }
        
        return maxSumMinProduct % 1000000007;
    }
};
