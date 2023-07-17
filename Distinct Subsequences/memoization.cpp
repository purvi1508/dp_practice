class Solution {
public:
    int count_r(string& s, string& t, int i, int j, vector<vector<int>>& memo) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int count = 0;
        if (s[i] == t[j]) {
            count += count_r(s, t, i - 1, j - 1, memo);
        }
        count += count_r(s, t, i - 1, j, memo);
        memo[i][j] = count;
        return count;
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return count_r(s, t, n - 1, m - 1, memo);
    }
};
