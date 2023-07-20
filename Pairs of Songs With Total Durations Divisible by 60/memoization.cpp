class Solution {
public:
    int select(vector<int>& time, int i, int count, int sum, vector<vector<vector<int>>>& memo) {
        if (i < 0 || count == 2) {
            if (count == 2 && sum % 60 == 0) {
                return 1;
            }
            return 0;
        }
        
        if (memo[i][count][sum] != -1) {
            return memo[i][count][sum];
        }

        int includeCurrent = select(time, i - 1, count + 1, (sum + time[i]) % 60, memo);
        int excludeCurrent = select(time, i - 1, count, sum, memo);

        memo[i][count][sum] = includeCurrent + excludeCurrent;
        return memo[i][count][sum];
    }

    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<vector<vector<int>>> memo(time.size(), vector<vector<int>>(3, vector<int>(60, -1)));
        return select(time, time.size() - 1, 0, 0, memo);
    }
};
