class Solution {
public:
    long long count(vector<vector<int>>& questions,int n){
        if(n>=questions.size()){
            return 0;
        }
        long long accept=questions[n][0]+count(questions,n+questions[n][1]+1);
        long long not_accept=count(questions,n+1);
        return max(accept,not_accept);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return count(questions,0);
    }
};
