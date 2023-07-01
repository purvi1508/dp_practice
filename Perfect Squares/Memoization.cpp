class Solution {
public:
    int numSquaresRecursive(int n, vector<int>& dp) {
        // Base cases
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int minSquares = n; // Initialize with the maximum possible value
        
        // Try all perfect squares less than or equal to n
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            int remaining = n - square;
            minSquares = min(minSquares, numSquaresRecursive(remaining, dp) + 1);
        }
        
        dp[n] = minSquares; // Store the result for future use
        return minSquares;
    }

    int numSquares(int n) {
       vector<int> dp(n + 1, -1); 
        return numSquaresRecursive(n, dp);
    }

};
