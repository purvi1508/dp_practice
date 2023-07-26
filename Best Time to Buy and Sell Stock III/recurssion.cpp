class Solution {
public: 
    int prof(vector<int>& prices,int i,int buy,int n,int count){
        if(i==n || count>2){
            return 0;
        }
        int price;
        if(buy==1){
            price=max((-prices[i]+prof(prices,i+1,0,n,count+1)),(prof(prices,i+1,1,n,count)));
        }
        else{
            price=max((prices[i]+prof(prices,i+1,1,n,count)),(prof(prices,i+1,0,n,count)));
        }
        return price;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return prof(prices,0,1,n,0);
    }
};
