class Solution {
public:
    int maxi(vector<int>& prices,int fee,int i,int buy,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int price=0;
        if(buy==1){
            price=max((-prices[i]+maxi(prices,fee,i+1,0,dp)),(maxi(prices,fee,i+1,1,dp)));
        }
        else{
            price=max((prices[i]+maxi(prices,fee,i+1,1,dp)-fee),(maxi(prices,fee,i+1,0,dp)));
        }
        dp[i][buy]=price;
        return price;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return maxi(prices,fee,0,1,dp);
    }
};
