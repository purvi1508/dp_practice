class Solution {
public:
    int maxi(vector<int>& prices,int i,int j,int n){
        if(i==n){
            return 0;
        }
        int profit;
        if(j==0){
            profit=max((-prices[i]+maxi(prices,i+1,1,n)),maxi(prices,i+1,0,n));
        }
        else{
            profit=max((prices[i]+maxi(prices,i+1,0,n)),maxi(prices,i+1,1,n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return maxi(prices,0,0,n);
    }
};
