class Solution {
public:
    int f(vector<vector<int>>&grid , int i , int j , vector<vector<int>>&dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(grid , i , j-1 , dp);
        int up = f(grid , i-1 , j , dp);

        return dp[i][j] = grid[i][j] + min(left , up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp (rows , vector<int>(cols , -1));
        return f(grid , rows-1 , cols-1 , dp);
    }
};