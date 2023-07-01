class Solution {
public:
    int numSquaresRecursive(int n) {
        // Base cases
        if (n == 0) return 0;
        
        int minSquares = n; // Initialize with the maximum possible value
        
        // Try all perfect squares less than or equal to n
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            int remaining = n - square;
            minSquares = min(minSquares, numSquaresRecursive(remaining) + 1);
        }
        
        return minSquares;
    }

    int numSquares(int n) {
        return numSquaresRecursive(n);
    }

};
