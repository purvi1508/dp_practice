class Solution {
public:
    int mini(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>&memo){
        if (row == triangle.size()) {
            return 0;
        }
        if(memo[row][col]!=-1){
            return memo[row][col];
        }
        int bottom=triangle[row][col]+ mini(triangle,row+1,col,memo);
        int right=triangle[row][col]+ mini(triangle,row+1,col+1,memo);
        memo[row][col]=min(bottom,right);
        return memo[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
     vector<vector<int>>memo(triangle.size(),vector<int>(triangle.size(),-1));
     return mini(triangle,0,0,memo);   
    }
};
