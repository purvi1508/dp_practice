class Solution {
public:
    int lcs(string word1, string word2, int i, int j, vector<vector<int>>& memo) {
        if (i < 0 || j < 0) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int result;
        if (word1[i] == word2[j]) {
            result = 1 + lcs(word1, word2, i - 1, j - 1, memo);
        } else {
            int insert = lcs(word1, word2, i, j - 1, memo);
            int deleteOp = lcs(word1, word2, i - 1, j, memo);
            result = max(insert, deleteOp);
        }
        
        memo[i][j] = result;
        return result;
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int lcsLength = lcs(word1, word2, n - 1, m - 1, memo);
        return (n - lcsLength) + (m - lcsLength);
    }
};
