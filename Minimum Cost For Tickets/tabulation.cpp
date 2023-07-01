class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
       
        vector<int> dp(n + 1, 0); // dp[i] represents the minimum cost to travel on or after day i

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + costs[0]; // Try using a 1-day pass for the current day

            int j = i;
            while (j < n && days[j] < days[i] + 7) {
                j++;
            }
            dp[i] = min(dp[i], dp[j] + costs[1]); // Try using a 7-day pass starting from the current day

            while (j < n && days[j] < days[i] + 30) {
                j++;
            }
            dp[i] = min(dp[i], dp[j] + costs[2]); // Try using a 30-day pass starting from the current day
        }

        return dp[0]; // Return the minimum cost to travel on or after the first day
    }
};
