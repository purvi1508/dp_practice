class Solution {
public:
    int change(vector<int>& coins, int amount, int n) {
        if (n == 0) {
            if (amount % coins[n] == 0) {
                return amount / coins[n];
            } else {
                return 1e9;
            }
        }

        int notTake = change(coins, amount, n - 1);
        int take = 1e9;
        if (coins[n] <= amount) {
            take = 1+ change(coins, amount - coins[n], n);
        }

        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
       if(change(coins, amount, coins.size() - 1)==1e9){
           return -1;
       }
       return change(coins, amount, coins.size() - 1);
    }
};
