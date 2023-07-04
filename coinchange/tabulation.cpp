class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        for(int i=0;i<coins.size();i++){
            dp[i][0]=0;//if(amount==0)
        }
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int take=1e9;
                if(j>=coins[i]){
                take=1+dp[i][j-coins[i]];
                }
                int nottake=1e9;
                if(i>0){
                nottake=dp[i-1][j];
                }
                dp[i][j]=min(take,nottake);
            }
        }
         return (dp[coins.size() - 1][amount] > amount) ? -1 : dp[coins.size() - 1][amount];
    }
};
