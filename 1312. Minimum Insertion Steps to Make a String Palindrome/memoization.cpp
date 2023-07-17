class Solution {
public:
    int count_min(string s, int i, int j, vector<vector<int>>& memo) {
        if (i >= j) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int result;
        if (s[i] == s[j]) {
            result = count_min(s, i + 1, j - 1, memo);
        } else {
            int insertFront = 1 + count_min(s, i, j - 1, memo);
            int insertEnd = 1 + count_min(s, i + 1, j, memo);
            result = min(insertFront, insertEnd);
        }
        
        memo[i][j] = result;
        return result;
    }

    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return count_min(s, 0, n - 1, memo);
    }
};
