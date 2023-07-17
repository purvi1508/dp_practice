class Solution {
public:
    int count_min(string s, int i, int n) {
        if (i >= n) {
            return 0;
        }
        if (s[i] == s[n]) {
            return count_min(s, i + 1, n - 1);
        }
        return min((1 + count_min(s, i, n - 1)), (1 + count_min(s, i + 1, n)));
    }

    int minInsertions(string s) {
        return count_min(s, 0, s.length() - 1);
    }
};
