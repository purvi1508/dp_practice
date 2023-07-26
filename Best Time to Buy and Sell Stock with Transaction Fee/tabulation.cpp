class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int price=0;
                if(j==1){
                    price=max((-prices[i]+dp[i+1][0]),dp[i+1][1]);
                }
                else{
                    price=max((prices[i]+dp[i+1][1]-fee),dp[i+1][0]);
                }
                dp[i][j]=price;
            }
        }
        return dp[0][1];
    }
};
