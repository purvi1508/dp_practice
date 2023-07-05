class Solution {
public:
    long long count(vector<vector<int>>& questions,int n,vector<long long>&dp){
        if(n>=questions.size()){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        long long accept=questions[n][0]+count(questions,n+questions[n][1]+1,dp);
        long long not_accept=count(questions,n+1,dp);
        dp[n]=max(accept,not_accept);
        return max(accept,not_accept);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(),-1);
        return count(questions,0,dp);
    }
};
