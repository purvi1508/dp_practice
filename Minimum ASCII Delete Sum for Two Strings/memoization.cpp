class Solution {
public: 
    int sum(string s,int m){
        int ans=0;
        for(int i=0;i<m;i++){
            ans+=int(s[i]);
        }
        return ans;
    }
    int mini_ans(string s1, string s2, int i, int j,vector<vector<int>> &memo) {
        if (i < 0) {
            return sum(s2,j+1);
        }
        if(j<0){
            return sum(s1,i+1);
        }
        if (s1[i] == s2[j]) {
            return mini_ans(s1, s2, i - 1, j - 1,memo);
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int delleft = int(s1[i]) + mini_ans(s1, s2, i - 1, j,memo);
        int delright = int(s2[j]) + mini_ans(s1, s2, i, j - 1,memo);
        return memo[i][j]=min(delleft, delright);
        return memo[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> memo(s1.length(),vector<int>(s2.length(),-1));
        return mini_ans(s1, s2, s1.length() - 1, s2.length() - 1,memo);
    }
};
