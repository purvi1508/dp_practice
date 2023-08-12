class Solution {
public:
    vector<vector<int>> memo; 
    
    int maxi(int n, int k) {
        if (n <= 2) {
            return 1;
        }
        
        if (memo[n][k] != -1) {
            return memo[n][k]; 
        }
        
        int maxProduct = 0;
        
        for (int j = 1; j < n; j++) {
            int product = max(j * (n - j), j * maxi(n - j, k - 1));
            maxProduct = max(maxProduct, product);
        }
        
        memo[n][k] = maxProduct; 
        
        return maxProduct;
    }
    
    int integerBreak(int n) {
        memo.assign(n + 1, vector<int>(n + 1, -1)); 
        return maxi(n, n);
    }
};
