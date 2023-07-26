class Solution {
public:
    int prof(vector<int>& prices, int i, int buy, int n, int count, vector<vector<vector<int>>>& memo) {
        if (i == n || count > 2) {
            return 0;
        }

        if (memo[i][buy][count] != -1) {
            return memo[i][buy][count];
        }

        int price;
        if (buy == 1) {
            price = max((-prices[i] + prof(prices, i + 1, 0, n, count + 1, memo)), (prof(prices, i + 1, 1, n, count, memo)));
        } else {
            price = max((prices[i] + prof(prices, i + 1, 1, n, count, memo)), (prof(prices, i + 1, 0, n, count, memo)));
        }

        memo[i][buy][count] = price;
        return price;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return prof(prices, 0, 1, n, 0, memo);
    }
};
