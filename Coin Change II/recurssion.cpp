class Solution {
public:
    int changing(int amount, vector<int>& coins, int n) {

        if (n==0) {
            if (amount%coins[n] == 0) {
                return 1;
            } 
            return 0;
        }

        
        int consider=0;
        if(amount>=coins[n]){
            consider = changing(amount - coins[n], coins, n );
        }
        int not_consider = changing(amount, coins, n - 1);
        return consider + not_consider;
    }

    int change(int amount, vector<int>& coins) {
        return changing(amount, coins, coins.size() - 1);
    }
};
