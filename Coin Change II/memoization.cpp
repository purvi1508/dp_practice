class Solution {
public:
    int changing(int amount, vector<int>& coins, int n,vector<vector<int>>&memo) {

        if (n==0) {
            if (amount%coins[n] == 0) {
                return 1;
            } 
            return 0;
        }
        if(memo[n][amount]!=-1){
            return memo[n][amount];
        }
        int consider=0;
        if(amount>=coins[n]){
            consider = changing(amount - coins[n], coins, n,memo );
        }
        int not_consider = changing(amount, coins, n - 1,memo);
        memo[n][amount]=consider + not_consider;
        return memo[n][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>memo(coins.size(),vector<int>(amount+1,-1));
        return changing(amount, coins, coins.size() - 1,memo);
    }
};
