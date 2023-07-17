class Solution {
public:
    int count_r(string& s, string& t, int i, int j) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (s[i] == t[j]) {
            return count_r(s, t, i - 1, j - 1) + count_r(s, t, i - 1, j);
        }
        return count_r(s, t, i - 1, j);
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        return count_r(s, t, n - 1, m - 1);
    }
};
