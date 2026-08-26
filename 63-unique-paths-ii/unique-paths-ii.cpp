class Solution {
public:
    int findPaths(vector<vector<int>>&grid , int i , int j , vector<vector<int>>&dp){
        if((i == 0 && j == 0) && grid[i][j] != 1) return 1;
        if((i < 0 || j < 0) || grid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int left = findPaths(grid , i , j-1 , dp);
        int up = findPaths(grid , i-1 , j , dp);

        return dp[i][j] =  left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //Apply Memoization
        // vector<vector<int>>dp(m , vector<int>(n , -1));
        // return findPaths(grid , m-1 , n-1 , dp); // Memoization


        //Tabulation
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if((i == 0 && j == 0) && grid[i][j] != 1){
        //             dp[0][0] = 1;
        //             continue;
        //         }
        //         if(grid[i][j] == 1){
        //             dp[i][j] = 0;
        //             continue;
        //         }
        //         int left = 0, up = 0;
        //         if(i > 0) up = dp[i-1][j];
        //         if(j > 0) left = dp[i][j-1];

        //         dp[i][j] = left + up;
        //     }
        // }
        // return dp[m-1][n-1];

        // Space Optimization

        vector<int>prev(n , 0);

        for(int i=0;i<m;i++){
            vector<int>curr(n , 0);
            for(int j=0;j<n;j++){
                if((i == 0 && j == 0) && grid[i][j] != 1){ 
                    curr[j] = 1;
                    continue;
                }
                if(grid[i][j] == 1){ 
                    curr[j] = 0;
                    continue;
                }
                int left = 0, up = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j-1];

                curr[j] = left + up;
            }
            prev = curr;
        }
        return prev[n-1];
    }
};