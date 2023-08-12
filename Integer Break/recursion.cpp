class Solution {
public:
    int maxi(int n){
         if (n <= 2) {
            return 1; 
        }
        
        int maxProduct = 0;
        
        for (int j = 1; j < n; j++) {
            int product = max(j * (n - j), j * integerBreak(n - j));
            maxProduct = max(maxProduct, product);
        }
        
        return maxProduct;
    }
    int integerBreak(int n) {
        return maxi(n);
    }
};
