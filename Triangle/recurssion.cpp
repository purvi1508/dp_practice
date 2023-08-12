class Solution {
public:
    int mini(vector<vector<int>>& triangle,int row,int col){
        if (row == triangle.size()) {
            return 0;
        }
        int bottom=triangle[row][col]+ mini(triangle,row+1,col);
        int right=triangle[row][col]+ mini(triangle,row+1,col+1);
        return min(bottom,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
     return mini(triangle,0,0);   
    }
};
