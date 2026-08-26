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
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp (m , vector<int>(n , -1));
        // return f(grid , m-1 , n-1 , dp); // Recurrence + Memoization

        //Tabulation

        // dp[0][0] = grid[0][0];
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i == 0 && j == 0) continue;

        //         int up = INT_MAX, left = INT_MAX;

        //         if(i > 0) up = dp[i-1][j];
        //         if(j > 0) left = dp[i][j-1];

        //         dp[i][j] = grid[i][j]  + min(left , up);
        //     }
        // }
        // return dp[m-1][n-1];


        //Space Optimization

        vector<int>prev (n , 0);

        for(int i=0;i<m;i++){
            vector<int>curr(n , 0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j] = grid[0][0];
                    continue;
                }

                int left = INT_MAX;

                int up = INT_MAX;
                
                if(i > 0){
                    up = prev[j];
                }
                if(j > 0) left = curr[j-1];

                curr[j] = grid[i][j]  + min(up , left);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};