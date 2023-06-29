class Solution {
public:
    int minCoststart0(vector<int>& cost,int i){
        if(i>=cost.size()){
            return 0;
        }
        int left=cost[i]+minCoststart0(cost,i+1);
        int right=cost[i]+minCoststart0(cost,i+2);
        return min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
       int check0=minCoststart0(cost,0);
       int check1=minCoststart0(cost,1);
       return min(check0,check1);
    }
};
